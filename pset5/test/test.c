#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    for (int i = 1; i <= 26; i++)
    {
        for (int j = 1; j <=26; j++)
        {
            printf("The results is: %i \n", i*j);
        }
    }
}