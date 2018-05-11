/*
 *
 * main.c - signature
 *
 * (c) 2018 gdifiore <difioregabe@gmail.com>
 *
 */


#include <stdio.h> 
#include <string.h>
#include "../include/signature.h"
#include "../include/common.h"

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("[!] Incorrect number of arguments\n\n");
        printf("[!] Format should be\n %s [input file or text]\n", argv[0]);
        return 1;
    } 
    if (strcmp(argv[1], "-v") == 0) {
        printf("signature %s by %s", AUTHOR, SIGNATURE_VERSION);
    }
    else {
        char *to_hash = argv[2];
        grab(argc, argv, to_hash);
    }

    return 0;
}