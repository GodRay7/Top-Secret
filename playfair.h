 #define ALPHA "ABCDEFGHIJKLMNOPQRSTUVXYZ"
 
 char* playfair_encrypt(const char* key, const char* text);

 char* playfair_decrypt(const char* key, const char* text);

char to_upper(char c);

void matrix(const char* key, char matrix[5][5]);

void buildMatrix(char matrix[5][5]);

void find_pos(char matrix[5][5], char c, int* row, int* col);

 