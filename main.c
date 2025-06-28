#include <stdio.h>
#include <stdlib.h>
#include "playfair.h"

int main()
{
    const char* key = "please";
    const char* text = "Taxxxiii";

    char* cipher = playfair_encrypt(key, text);
    if (cipher != NULL) {
        printf("Encrypted: %s\n", cipher);
    } else {
        printf("Error\n");
    }

    char* decoded = playfair_decrypt(key, cipher);
    if (decoded != NULL) {
        printf("Decrypted: %s\n", decoded);
        free(decoded);  
    } else {
        printf("Error\n");
    }

    free(cipher);
    return 0;
}