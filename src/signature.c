/*
 *
 * signature.c - signature
 *
 * (c) 2018 gdifiore <difioregabe@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "openssl/sha.h"
#include "../include/signature.h"

static int is_filename(char *name)
{
	if (access(name, F_OK) != -1)
		return 1;
	else
		return 0;
}

#define READ_SIZE 32768
int sha256_file (char* to_hash, unsigned char *digest)
{
	char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	char *buffer = NULL;
	const int bufsize = READ_SIZE;
	int bytes_read = 0;

	FILE *file = fopen(to_hash, "rb");
	if (!file) {
		printf("%s: cannot open %s\n", __func__, to_hash);
		return -1;
	}

	SHA256_Init(&sha256);

	buffer = malloc(bufsize);
	if (!buffer) {
		printf("%s: malloc failed\n", __func__);
		fclose(file);
		return -1;
	}

	while((bytes_read = fread(buffer, 1, bufsize, file)))
		SHA256_Update(&sha256, buffer, bytes_read);

	SHA256_Final(digest, &sha256);

	fclose(file);
	free(buffer);

	return 0;
}

void sha256_string(char* str, unsigned char *digest)
{
	SHA256_CTX c;
	SHA256_Init(&c);
	SHA256_Update(&c, str, strlen(str));
	SHA256_Final(digest, &c);
}

void print_hex_hash(unsigned char* digest, int length)
{
	int i;
	for(i=0; i < length; i++)
		printf("%02x", digest[i]);
}


int grab (int argc, char **argv, char *to_hash) {
	unsigned char sha256_digest[SHA256_DIGEST_LENGTH];
	int i = 0;

	for (i = 1; i < argc; i++) {
		if (is_filename(argv[i])) {
			printf("SHA256 of file \"%s\" is: ", argv[i]);
			sha256_file(argv[i], sha256_digest);
		} else {
			printf("SHA256 of string \"%s\" is: ", argv[i]);
			sha256_string(argv[i], sha256_digest);
		}
		print_hex_hash(sha256_digest, SHA256_DIGEST_LENGTH);
		printf("\n");
	};
}