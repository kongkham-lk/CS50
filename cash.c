
#include <cs50.h>
#include <math.h>
#include <stdio.h>


int main(void)
{
    //Prompt user input - Change owed
    float i;
    do
    {
        i = get_float("Change owed: \n");
        
    }
    while (i < 0);
    
    //Removing decimal
    int cent = round(i * 100);
    
    //Coin number starting number
    int coin = 0;
    
    //Getting Coin number base in input number value range
    while (cent >= 25)
    {
        cent = cent - 25;
        coin ++;
    }
    while (cent >= 10)
    {
        cent = cent - 10;
        coin ++; 
    }
    while (cent >= 5)
    {
        cent = cent - 5;
        coin ++; 
    }
    while (cent >= 1)
    {
        cent = cent - 1;
        coin ++; 
    }
    
    //Print out coin number
    printf("%i\n", coin);
}
