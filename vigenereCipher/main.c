#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"


int main() {
    const char* key = "CoMPuTeR";
    const char* text = "Hello world!";

    printf("Text: %s\n", text);

    char* encrypted = vigenere_encrypt(key, text);
    if (encrypted) {
        printf("Encrypted: %s\n", encrypted);

        char* decrypted = vigenere_decrypt(key, encrypted);
        if (decrypted) {
            printf("Decrypted: %s\n", decrypted);
            free(decrypted);
        }

        free(encrypted);
    } else {
        printf("Error\n");
    }
    return 0;
}