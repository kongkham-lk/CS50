#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // User prompt for Text Input
    string text = get_string("Text: ");
    
    int L = 0;
    int W = 1;
    int S = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Counting Letter's Number
        if (isalpha(text[i]))
        {
            L++;
        }
        
        // Counting Wording - according to the space "\0" and excluding puntuations
        if (isalpha(text[i]) == '\0')
        {
            W++;
        }
        
        if (ispunct(text[i]))
        {
            W--;
        }
        
        // Counting Sentence Number - checking Ending Symbol
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            S++;
        }
    }
    
    // Putting all the above value into the fomular 
    float index = 0.0588 * ((float) L / W * 100) - 0.296 * ((float) S / W * 100) - 15.8;
    
    if (index <= 16 && index > 1)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
