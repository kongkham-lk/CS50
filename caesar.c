#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // CHECKING FOR 2 INPUT
    if (argc != 2)
    {
        printf("Usage: %s KEY\n", argv[0]);
        return 1;
    }

    // CHECKING FOR NON ALPHABETIC CHARACTR
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: %s KEY\n", argv[0]);
            return 1;
        }
    }

    // USER PROMPT
    string plain = get_string("plaintext: ");

    printf("ciphertext: ");

    // CONVERTING STRING TO INTERGER
    int key = atoi(argv[1]);

    for (int i = 0; i < strlen(plain); i++)
    {
        // ROTATING CHARACTER - BASED ON IPUT VALUE
        int cipher = (int)plain[i] + key;

        if (isalpha(plain[i]))
        {
            if (islower(plain[i]))
            {
                // GETTING THE REMAINDER VALUE OF CHARACTER
                while (cipher > 'z')
                {
                    cipher = cipher - 26;
                }
                printf("%c", cipher);
            }
            if (isupper(plain[i]))
            {
                // GETTING THE REMAINDER VALUE OF CHARACTER
                while (cipher > 'Z')
                {
                    cipher = cipher - 26;
                }
                printf("%c", cipher);
            }
        }
        // REMAIN FOR NON ALPHABETIC CHARACTR
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}
