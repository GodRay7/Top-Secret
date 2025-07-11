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

      if (!used[c - 'A']) { //in ACII table 'A' = 65 so c - 'A' = c - 65
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

void find_pos(char matrix[5][5], char c, int* row, int* col) {
   for (int i = 0; i < 5 ; i++) {
      for (int j = 0; j < 5; j++) {
         if (matrix[i][j] == c) {
            *row = i;
            *col = j;
            return;
         }
      }
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
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        c = to_upper(c);
        if (c == 'W') c = 'V';
        copy_text[newTextIndex++] = c;
    }
   }

   for (int i = 0; i < newTextIndex; i += 2) {
      if (i + 1 == newTextIndex) {
        copy_text[newTextIndex++] = 'X';
        break;
      }

      if ((copy_text[i] == copy_text[i + 1]) && (copy_text[i] == copy_text[i + 2])) {
         continue;
         newTextIndex++;
      }else if (copy_text[i] == copy_text[i + 1]) {
         for (int j = newTextIndex; j > i + 1; j--) {
            copy_text[j] = copy_text[j - 1];
         }
         copy_text[i + 1] = 'X';
         newTextIndex++;
      }
    
   }

   if (newTextIndex % 2 != 0) {
      copy_text[newTextIndex++] = 'X';
   }
   copy_text[newTextIndex] = '\0';
   
   // printf("%s\n", copy_text);
   
   int tLen = strlen(copy_text);
   char* cipher = malloc(tLen + 1);
   int c_idx = 0;

   for (int i = 0; i < tLen; i += 2) {
      char x = copy_text[i];
      char y = copy_text[i + 1];
      int row1, row2, col1, col2;
      
      find_pos(mat, x, &row1, &col1);
      find_pos(mat, y, &row2, &col2);

      if (row1 == row2) {
         cipher[c_idx++] = mat[row1][(col1 + 1) % 5];
         cipher[c_idx++] = mat[row2][(col2 + 1) % 5];
         // cipher[c_idx++] = ' ';
      } else if (col1 == col2) {
         cipher[c_idx++] = mat[(row1 + 1) % 5][col1];
         cipher[c_idx++] = mat[(row2 + 1) % 5][col2];
         // cipher[c_idx++] = ' ';
      } else {
         cipher[c_idx++] = mat[row1][col2];
         cipher[c_idx++] = mat[row2][col1];
         // cipher[c_idx++] = ' ';
      } 
   }  
   

   cipher[c_idx] = '\0';
   return cipher;
 }

 char* playfair_decrypt(const char* key, const char* text)
 {
   char mat[5][5];
   matrix(key, mat);

   int cLen = strlen(text);
   char* decoded = malloc(cLen + 1);
   int de_idx = 0;

   
   for (int i = 0; i < cLen; i += 2) {

      char x = text[i];
      char y = text[i + 1];
      int row1, row2, col1, col2;

      find_pos(mat, x, &row1, &col1);
      find_pos(mat, y, &row2, &col2);

      if (row1 == row2) {
         decoded[de_idx++] = mat[row1][(col1 + 4) % 5];
         decoded[de_idx++] = mat[row2][(col2 + 4) % 5];
      } else if (col1 == col2) {
         decoded[de_idx++] = mat[(row1 + 4) % 5][col1];
         decoded[de_idx++] = mat[(row2 + 4) % 5][col2];
      } else {
         decoded[de_idx++] = mat[row1][col2];
         decoded[de_idx++] = mat[row2][col1];
      } 
   }

   decoded[de_idx++] = '\0';
   return decoded;
 }
 



