#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playfair.h"

void matrix (const char* key, char matrix[5][5])
{
   char alphabet[26] = ALPHA;
   int used[26] = {0};
   int counter = 0;

   for (int i = 0; key[i] != '\0'; i++) {

      char c = key[i];
   

      if (c >= 'a' && c <= 'z') {
         c = c - 32;
      }

      if (c == 'W') {
         c = 'V';
      }

      if (c < 'A' || c > 'Z') {
         continue;
      }

      if (!used[c - 'A']) {
         used[c - 'A'] = 1;
         matrix[counter / 5][counter % 5] = c;
         counter++;
         if(counter >= 25) {
            return;
         }
      }

   }

   for (int i = 0; alphabet[i] != '\0'; i++) {
      char c = alphabet[i];
      if (!used[c - 'A']) {
         used[c - 'A'] = 1;
         matrix[counter / 5][counter % 5] = c;
         counter++;
         if(counter >= 25) {
            return;
         }
      }
   }
      

}

void buildMatrix (char matrix[5][5]) {
   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++){
         printf("%c ", matrix[i][j]);
      }
      printf("\n");
   }
}

 char* playfair_encrypt(const char* key, const char* text)
 {
   
 }
 



