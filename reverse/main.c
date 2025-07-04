#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"


int main()
{
    char* reversed = reverse("Hello world!");
    printf("%s\n", reversed);

    return 0;
}