#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    double StartSize;   //initialise StartSize for wfile loop
    do
    {
        StartSize = get_double("Start size: ");  //asks user starting size
    }
    while (StartSize < 9);

    double EndSize; //initialise Endsize for while loop
    do
    {
        EndSize = get_double("End size: ");   //asks user end size
    }
    while (EndSize < StartSize);

    if (StartSize == EndSize)   //Special condition definition
    {
        printf("Years: 0");
        return 0;
    }

    double CurrentYear = StartSize;
    int Count = 0;
    while (CurrentYear < EndSize)
    {
        double GrowYear = floor(CurrentYear / 3);
        double DeathYear = floor(CurrentYear / 4);
        CurrentYear = CurrentYear + GrowYear - DeathYear;
        printf("What is the number of years %f\n", CurrentYear);
        Count = Count + 1;
    }

    printf("Years: %i\n", Count);
}
