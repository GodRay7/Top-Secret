#include <stdio.h>
#include <stdlib.h>
#include "playfair.h"

int main()
{
    char mat[5][5];
    matrix("SeCrEt", mat);
    buildMatrix(mat);

    return 0;
}