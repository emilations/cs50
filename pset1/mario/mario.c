#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");   //ask the user for the height
    }
    while (!((height >= 1) && (height <= 8)));

    for (int i = 1; i <= height; i++)
    {
        for (int k = 1; k <= (height - i); k++)
        {
            printf(" ");    //prints the blank space of the triangle
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");    //prints the tyesriangle iterations
        }
        printf("\n");
    }
}