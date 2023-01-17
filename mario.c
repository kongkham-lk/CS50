#include "cs50.h"
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        // Getting user input of Pyramic Height
        height = get_int("Piramid Height: \n");
    }
    // Getting only the range of number - 1 to 8
    while (height < 1 || height > 8);

    // Adding block height that depend on input value
    int x = height;
    for (int i = 1; i <= x; i++)
    {
        for (int j = x - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf(" ");
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
