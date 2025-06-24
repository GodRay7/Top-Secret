#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playfair.h"

char to_upper(char c) {
   if (c >='a' && c<= 'z') {
      return c - 32;
   }
   return c;
}

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
   char mat[5][5];
   matrix(key, mat);
   buildMatrix(mat);

   int textLen = strlen(text);
   int bigTextLen = textLen * 2;
   char copy_text[bigTextLen];
   int newTextIndex = 0;

   for (int i = 0; i < textLen; i++) {
      char c = text[i];
      if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
         return NULL;  
      }

      if(c == ' ') continue;
      copy_text[newTextIndex] = to_upper(c);
      if (copy_text[newTextIndex] == 'W') {
         copy_text[newTextIndex] = 'V';
      }
      newTextIndex++;
   }
   copy_text[newTextIndex] = '\0';

   for (int i = 0; i < bigTextLen; i += 2) {
      if (copy_text[i] == copy_text[i + 1] && copy_text[i] != 'X') {
         for (int j = bigTextLen - 1; j >= i + 2; j--) {
            copy_text[j] = copy_text[j - 1];
         }
         copy_text[i + 1] = 'X';
      }
      if (copy_text[i] != '\0' && copy_text[i + 1] == '\0') {
         copy_text[i + 1] = 'X';
         copy_text[i + 2] = '\0';
      }
   }
   printf("%s\n", copy_text);
   return NULL;
 }
 



