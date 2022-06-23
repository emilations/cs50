#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float amount1;
    do
    {
        amount1 = get_float("Change owed: ");    //ask the user for the amount to break
    }
    while (amount1 < 0);

    int amount = round(amount1 * 100);  //round everything by extracting the two decimal points
    int n = 0; // the number of coins used
    int var1 = 25; //initializing the coins
    int var2 = 10;
    int var3 = 5;
    int var4 = 1;

    while (amount >= var1)
    {
        amount = amount - var1; //keep on removing 25c until there are no more complete whole 25c
        n++;
    }
    while (amount >= var2)
    {
        amount = amount - var2; //keep on removing 25c until there are no more complete whole 10c
        n++;
    }
    while (amount >= var3)
    {
        amount = amount - var3; //keep on removing 25c until there are no more complete whole 5c
        n++;
    }
    while (amount >= var4)
    {
        amount = amount - var4; //keep on removing 25c until there are no more complete whole 1c
        n++;
    }
    printf("%i\n", n);
}