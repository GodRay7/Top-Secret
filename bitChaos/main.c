#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"


int main()
{
    unsigned char* encrypted = bit_encrypt("Hello world!");
    if (!encrypted) {
        printf("Error\n");
        return 1;
    }

    printf("Encrypted: ");
    for (int i = 0; encrypted[i] != '\0'; i++) {
        printf("%02X ", encrypted[i]);
    }
    printf("\n");

    free(encrypted);
    return 0;
}