#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // test for having more than one argument
    if (argc != 2)
    {
        printf("Usage: ./vigenere k");
        return 1;
    }

    // test for argument containing non-letters
    string cypher = argv[1];
    for (int i = 0; i < strlen(cypher); i++)
    {
        if (!isalpha(cypher[i]))
        {
            printf("error\n");
            return 1;
        }
    }
    // get user input to encrypt
    string plaintext = get_string("plaintext: ");

    // loop through user input string
    printf("ciphertext: ");
    int skipcounter = 0;
    for (int i = 0, j = strlen(cypher); i < strlen(plaintext); i++)
    {
        // check for non-alphabet so no encryption will occur and skipcounter checks how many steps behind the cypher should be
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            skipcounter ++;
        }
        else
        {
            // ascii of char to convert
            int asciival = plaintext[i];
            // ascii of char to encrypt with
            int cypherascii = cypher[((i - skipcounter) % j)];
            // lowercase cypher
            if (cypherascii >= 97)
            {
                cypherascii -= 97;
            }
            // uppercase cypher
            else if (cypherascii >= 65)
            {
                cypherascii -= 65;
            }
            else
            {
                printf("cypher error");
                return 1;
            }
            // lowercase char to encrypt
            if (asciival >= 97)
            {
                if (asciival + cypherascii <= 122)
                {
                    printf("%c", asciival + cypherascii);
                }
                else
                {
                    asciival = (96 + (cypherascii - (122 - asciival)));
                    printf("%c", asciival);
                }

            }
            // uppercase char to encrypt
            else if (asciival >= 65)
            {
                if (asciival + cypherascii <= 90)
                {
                    printf("%c", asciival + cypherascii);
                }
                else
                {
                    asciival = (64 + (cypherascii - (90 - asciival)));
                    printf("%c", asciival);
                }
            }
            else
            {
                printf("error in asciival for character to be converted");
            }
        }
    }
    printf("\n");

}