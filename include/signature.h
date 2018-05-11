/*
 *
 * signature.h - signature
 *
 * (c) 2018 gdifiore <difioregabe@gmail.com>
 *
 */

#ifndef __SIGNATURE_H
#define __SIGNATURE_H

static int is_filename(char *name);
int sha256_file (char* to_hash, unsigned char *digest);
void sha256_string(char* str, unsigned char *digest);
void print_hex_hash(unsigned char* digest, int length);
int grab(int argc, char **argv, char *to_hash);

#endif