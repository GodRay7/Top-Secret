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

char* reverse(const char* text)
{
    int textLen = strlen(text);
    char* changed = malloc((textLen + 1) * sizeof(char));
    if (changed == NULL) return NULL;
    
    
    for (int i = 0; i < textLen; i++) {
    char c = text[textLen - 1 - i];
    changed[i] = to_upper(c);
   }
    return changed;
}