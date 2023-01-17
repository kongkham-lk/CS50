#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string Convert(string key);

int main(int argc, string argv[])
{
    // CHECKING FOR USER KEY
    if (argc != 2)
    {
        printf("Usage: %s KEY\n", argv[0]);
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // CHECKING FOR KEY LENGTH
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        // CHECKING FOR NONE ALPHABETIC CHARACTER
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        // CHECKING FOR DUPLICATE CHARACTER
        for (int j = i + 1; j < n; j++)
        {
            // COVERTING ALL CHARACTER TO UPPERCASE
            string key = Convert(argv[1]);

            // COMPARING THE CURRENT AND THE NEXT CHARACTER
            if (key[i] == key[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // USER PROMPT
    string plain = get_string("plaintext: ");

    printf("ciphertext: ");

    // PRINTING INPUT BASED ON USER PROMPT
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isalpha(plain[i]))
        {
            // FINDING ALPHABET ORDER NUMBER >> "A" as "1"
            int l = toupper(plain[i]) - 'A';

            // PRINTING CIPHERTEXT - EACH CHARACTER IS BASED ON THE EARLIER USER PROMPT
            if (islower(plain[i]))
            {
                printf("%c", tolower(argv[1][l]));
            }
            if (isupper(plain[i]))
            {
                printf("%c", toupper(argv[1][l]));
            }
        }

        // UNCHANGE FOR NONE ALPHABETIC CHARACTER
        if (ispunct(plain[i]) || isdigit(plain[i]) || isspace(plain[i]))
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}

// COVERTING ALL CHARACTER TO UPPERCASE
string Convert(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        key[i] = toupper(key[i]);
    }
    return key;
}
