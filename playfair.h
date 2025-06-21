 #define ALPHA "ABCDEFGHIJKLMNOPQRSTUVXYZ"
 
 char* playfair_encrypt(const char* key, const char* text);

 char* playfair_decrypt(const char* key, const char* text);

 void buildMatrix (char matrix[5][5]);
 
 void matrix (const char* key, char matrix[5][5]);
 