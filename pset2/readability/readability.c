#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int lpara;
int cletters(string para);
int cwords(string para);
int csent(string para);

int main(void)
{
    string para = get_string("Text:");
    lpara = strlen(para);
    int numletter = cletters(para);
    int numwords = cwords(para);
    int numsent = csent(para);
    float L = 100 * ((float) numletter / (float) numwords);
    float S = 100 * ((float) numsent / (float) numwords);
    float index = round((0.0588 * L) - (0.296 * S) - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }
}

int cletters(string para)
{
    int n = 0; //n is the letter counter
    for (int i = 0; i < lpara; i++)
    {
        char cpara = toupper(para[i]); //convert all possible char to upper bcz easier if condition
        if (cpara >= 65 && cpara <= 90)
        {
            n++;    //incriment the counter when a letter is found
        }
    }
    return n;
}

int cwords(string para)
{
    int s = 1; //n is the number of words
    for (int i = 0; i < lpara; i++)
    {
        if (para[i] == 32)
        {
            s++;    //incriment the counter when a space is found
        }
    }
    return s;
}

int csent(string para)
{
    int n = 0; //n is the number of words
    for (int i = 0; i < lpara; i++)
    {
        if (para[i] == 33 || para[i] == 46 || para[i] == 63)
        {
            n++;    //incriment the counter when a . ? ! is found
        }
    }
    return n;
}