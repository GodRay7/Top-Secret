#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

char to_upper(char c) {
   if (c >='a' && c<= 'z') {
      return c - 32;
   }
   return c;
}

char* vigenere_encrypt(const char* key, const char* text)
{
    if (!key || !text) return NULL;

    int textLen = strlen(text);
    int keyLen = strlen(key);
    if (keyLen == 0) return NULL;

    char* result = malloc((textLen + 1) * sizeof(char));
    if (!result) return NULL;

    int key_idx = 0;

    for (int i = 0; i < textLen; i++) {
        char t = to_upper(text[i]);

        if ((t >= 'A' && t <= 'Z') || (t >= 'a' && t <= 'z')){
            char k = to_upper(key[key_idx % keyLen]);
            int shift = k - 65;
            result[i] =((t - 65 + shift) % 26) + 65;
            key_idx++;
        } else {
            result[i] = text[i];
        }  
    }
    result[textLen] = '\0';
    return result;
}

char* vigenere_decrypt(const char* key, const char* text)
{
    if (!key || !text) return NULL;

    int textLen = strlen(text);
    int keyLen = strlen(key);
    if (keyLen == 0) return NULL;

    char* result = malloc((textLen + 1) * sizeof(char));
    if (!result) return NULL;

    int key_idx = 0;

    for (int i = 0; i < textLen; i++) {
        char t = to_upper(text[i]);

        if ((t >= 'A' && t <= 'Z') || (t >= 'a' && t <= 'z')){
            char k = to_upper(key[key_idx % keyLen]);
            int shift = k - 65;
            result[i] =((t - 65 - shift + 26) % 26) + 65;
            key_idx++;
        } else {
            result[i] = text[i];
        }  
    }
    result[textLen] = '\0';
    return result;
}
