#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int key;
    //Print error if input dimensions is not equal to 1
    if (argc == 2)
    {
        key = atoi(argv[1]);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //check for non digit numbers
    int var1 = strlen(argv[1]);
    for (int i = 0; i < var1; i++)
    {
        if ((isdigit((char) argv[1][i])) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // ask user for text and calculates its length
    string text = get_string("plaintext: ");
    int n = strlen(text);
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        if (text[i] <= 90 && text[i] >= 65) //for uppercase letters
        {
            text[i] -= 64;
            text[i] = (text[i] + key) % 26;
            text[i] += 64;
        }
        if (text[i] <= 122 && text[i] >= 97) //for lowercase letters
        {
            text[i] -= 96;
            text[i] = (text[i] + key) % 26;
            text[i] += 96;
        }
        printf("%c", text[i]);
    }
    printf("\n");
}

