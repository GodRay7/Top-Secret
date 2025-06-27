#include <stdio.h>
#include <stdlib.h>
#include "playfair.h"

int main()
{
    const char* key = "SeCReT";
    const char* text = "Hello world";

    char* cipher = playfair_encrypt(key, text);
    if (cipher != NULL) {
        printf("Encrypted: %s\n", cipher);
    } else {
        printf("Error\n");
    }

    char* decrypted = playfair_decrypt(key, cipher);
    if (decrypted != NULL) {
        printf("Decrypted: %s\n", decrypted);
        free(decrypted);  
    } else {
        printf("Error in decryption\n");
    }

    free(cipher);
    return 0;
}