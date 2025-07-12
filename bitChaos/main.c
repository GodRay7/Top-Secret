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

    char* decrypted = bit_decrypt(encrypted);
    if (!decrypted) {
        printf("Error during decryption\n");
        free(encrypted);
        return 1;
    }

    printf("Decrypted: %s\n", decrypted);

    free(encrypted);
    free(decrypted);
    return 0;
}