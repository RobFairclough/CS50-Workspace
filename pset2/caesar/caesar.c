#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check number of arguments passed when running program - if no arguments passed or more than one, error.
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    else
    {
        // User input of string to encrypt
        string plaintext = get_string("plaintext: ");
        // passed argument
        int cypher = atoi(argv[1]);
        // account for shifting letter more than 26 places
        cypher = cypher % 26;
        // Loop through plaintext string
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // doesn't alter if character isn't a letter
            if (isalpha(plaintext[i]) == false)
            {
                printf("%c", plaintext[i]);
            }
            else
            {
                // ASCII:  uppercase A = 65, Z = 90 lowercase a = 97, z = 122;
                //getcharcode
                int asciiVal = plaintext[i];
                //altercharcode
                //uppercase
                if (asciiVal >= 65 && asciiVal <= 90)
                {
                    // check for overflow
                    if ((asciiVal + cypher) > 90)
                    {
                        asciiVal = (64 + (asciiVal + cypher - 90));
                        printf("%c", asciiVal);
                    }
                    else
                    {
                        printf("%c", asciiVal + cypher);
                    }
                }
                //lowercase
                else if (asciiVal >= 97 && asciiVal <= 122)
                {
                    if ((asciiVal + cypher) > 122)
                    {
                        asciiVal = (96 + (cypher - (122 - asciiVal)));
                        printf("%c", asciiVal);
                    }
                    else
                    {
                        printf("%c", asciiVal + cypher);
                    }
                }
            }
        }
        printf("\n");
    }
}