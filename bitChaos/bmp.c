#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

void letterToBit (unsigned char c, int* bits)
{
    int bit[8] = {128, 64, 32, 16, 8, 4, 2, 1};

    for (int i = 0; i < 8; i++) {
        if (c >= bit[i]) {
            c -= bit[i];
            bits[i] = 1;
        }else {
            bits[i] = 0;
        }
    }
}

void bitSwapper (int* first)
{
    for (int i = 0; i < 4 - 1; i += 2) {
        int temp = first[i];
        first[i] = first[i + 1];
        first[i + 1] = temp;
    }
}

unsigned char bitsToBit(int* bits)
{
    unsigned char result = 0;
    for (int i = 0; i < 4; i++) {
        result |= (bits[i] << (3 - i));
    }
    return result;
}

void bitsToArr(int* arr, unsigned char value) {
    for (int i = 0; i < 4; i++) {
        arr[i] = (value >> (3 - i)) & 1;
    }
}

unsigned char* bit_encrypt(const char* text)
{
   int Len = strlen(text);
   unsigned char* encrypted = malloc(Len + 1 * sizeof(unsigned char));
   if (!encrypted) return NULL;

   for (int i = 0; i < Len; i++) {
    int bits[8];

    letterToBit(text[i], bits);

    int first[4],second[4];
    for (int j = 0; j < 4; j++) {
        first[j] = bits[j];
        second[j] = bits[j + 4];
    }

    bitSwapper(first);

    int xored[4];
    for (int j = 0; j < 4; j++) {
        xored[j] = first[j] ^ second[j];
    }

    unsigned char left = bitsToBit(first);
    unsigned char right = bitsToBit(xored);

    encrypted[i] = (left << 4) | right;
   }
    encrypted[Len] = '\0';
    return encrypted;
}

char* bit_decrypt(const unsigned char* text)
{
    int Len = strlen((const char*)text);
    char* decrypted = malloc(Len + 1 * sizeof(char));
    if (!decrypted) return NULL;

    for (int i = 0; i < Len; i++) {
        unsigned char byte = text[i];
        unsigned char left = (byte >> 4);
        unsigned char right = byte;

        int first[4], xored[4], second[4], origBits[8];
        bitsToArr(first, left);
        bitsToArr(xored, right);

        for (int j = 0; j < 4; j++) {
            second[j] = first[j] ^ xored[j];
        }

        bitSwapper(first);

        for (int j = 0; j < 4; j++) {
            origBits[j] = first[j];
            origBits[j + 4] = second[j];
        }

        unsigned char c = 0;
        for (int j = 0; j < 8; j++) {
            c |= (origBits[j] << (7 - j));
        }
        decrypted[i] = c;
    }
    decrypted[Len] = '\0';
    return decrypted;
}