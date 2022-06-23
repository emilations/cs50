#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char var1 = '0';
    int var2 = isalnum(var1);
    printf("ew %b \n", var2);
}