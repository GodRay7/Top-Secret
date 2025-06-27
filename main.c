#include <stdio.h>
#include <stdlib.h>
#include "playfair.h"

int main()
{

    char* cipher = playfair_encrypt("SeCReT", "Hello world");

    if (cipher != NULL) {
        printf("Encrypted: %s\n", cipher);
        free(cipher);
    } else {
        printf("Error\n");
    }

    return 0;
}