#include<cs50.h>
#include<stdio.h>

int main(void)
{
    // Getting user prompt for credit card number
    long i = get_long("Credit card number: \n");
    
    // Getting no. of each digit within the input credit no.
    int x1 = (i % 10);
    int x2 = (i / 10 % 10);
    int x3 = (i / 100 % 10);
    int x4 = (i / 1000 % 10);
    int x5 = (i / 10000 % 10);
    int x6 = (i / 100000 % 10);
    int x7 = (i / 1000000 % 10);
    int x8 = (i / 10000000 % 10);
    int x9 = (i / 100000000 % 10);
    int x10 = (i / 1000000000 % 10);
    int x11 = (i / 10000000000 % 10);
    int x12 = (i / 100000000000 % 10);
    int x13 = (i / 1000000000000 % 10);
    int x14 = (i / 10000000000000 % 10);
    int x15 = (i / 100000000000000 % 10);
    int x16 = (i / 1000000000000000 % 10);
    
    //Calculating - multiplying every other digit by 2 (starting with the second last digit), then combine them
    int visa = ((x2 * 2 % 10) + (x2 * 2 / 10 % 10) + (x4 * 2 % 10) + (x4 * 2 / 10 % 10) + (x6 * 2 % 10) + (x6 * 2 / 10 % 10) +
                (x8 * 2 % 10) + (x8 * 2 / 10 % 10) + (x10 * 2 % 10) + (x10 * 2 / 10 % 10) + (x12 * 2 % 10) + (x12 * 2 / 10 % 10));    
    int american = (visa + (x14 * 2 % 10) + (x14 * 2 / 10 % 10));
    int master = (american + (x16 * 2 % 10) + (x16 * 2 / 10 % 10));

    // Sum up the remaining digit as well as the above resdult
    int sum_13 = (visa + x1 + x3 + x5 + x7 + x9 + x11 + x13);    
    int sum_15 = (american + x1 + x3 + x5 + x7 + x9 + x11 + x13 + x15);
    int sum_16 = (master + x1 + x3 + x5 + x7 + x9 + x11 + x13 + x15);
    
    // Ckecksum for AMERICAN EXPRESS
    if ((i < 10000000000000 || i > 100000000000000) && x15 == 3 && (x14 == 4 || x14 == 7) && sum_15 % 10 == 0)
    {
        printf("AMEX\n");
    }
    
    // Ckecksum for MASTERCARD
    else if ((i < 100000000000000 || i > 1000000000000000) && x16 == 5 
             && (x15 == 1 || x15 == 2 || x15 == 3 || x15 == 4 || x15 == 5) && sum_16 % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
    
    // Ckecksum for VISA
    else if (((i < 100000000000 || i > 1000000000000) || (i < 100000000000000 || i > 1000000000000000)) 
             && (x16 == 4 || x13 == 4) && (sum_13 % 10 == 0 || sum_16 % 10 == 0))
    {
        printf("VISA\n");
    }
    
    // Other than the above condition type of credit card will be considered "INVALID"
    else
    {
        printf("INVALID\n");
    }
}
