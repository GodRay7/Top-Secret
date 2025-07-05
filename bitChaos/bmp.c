#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

void letterToBit (unsigned char c, int* bits)
{
    int bits[8] = {128, 64, 32, 16, 8, 4, 2, 1};

    for (int i = 0; i < 8; i++) {
        if (c >= bits[i]) {
            c -= bits[i];
            bits[i] = 1;
        }else {
            bits[i] = 0;
        }
    }
}


unsigned char* bit_encrypt(const char* text)
{
    /*
    Hello world!
    change to bit

    H = 72
    128, 64, 32, 16, 8, 4, 2, 1

    there

    01001000
    split 4 and 4
    0100  1000
    change numbers in 1st group
    1000
    XOR 1000
        1000 1st group after change
        0000

    write together 1st group after change and resut of XOR
    10000000

    */
   
}