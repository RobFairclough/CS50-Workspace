#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <crypt.h>
#define _XOPEN_SOURCE

/* assumptions :
    hashed with c's des based crypt function (man crypt)
    hashing a word with same hash will always return same hash
    words no longer than 5 chars
    composed entirely of alphabetical chars

*/
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./crack hash");
    }
    // hash to check against
    string hash = argv[1];
    // array with room for 5 chars and a null terminator value
    char password[6];
    // the 'salt' of the hash
    char salt[3] = {hash[0], hash[1]};
    // alphabet array
    char alphabet[] =
    {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    // loop for each potential character in password
    for (int i = 0; i < 5; i++)
    {
        password[i + 1] = '\0';
        // loop for first char
        for (int j = 0; j < 51; j++)
        {
            password[0] = alphabet[j];
            if (strcmp(crypt(password, salt), hash) == 0)
            {
                printf("%s\n", password);
                return 0;
            }
            // loop for second char
            if (i > 0)
            {
                for (int k = 0; k < 51; k++)
                {
                    password[1] = alphabet[k];
                    if (strcmp(crypt(password, salt), hash) == 0)
                    {
                        printf("%s\n", password);
                        return 0;
                    }
                    // loop for third char
                    if (i > 1)
                    {
                        for (int l = 0; l < 51; l++)
                        {
                            password[2] = alphabet[l];
                            if (strcmp(crypt(password, salt), hash) == 0)
                            {
                                printf("%s\n", password);
                                return 0;
                            }
                            // loop for fourth char
                            if (i > 2)
                            {
                                for (int m = 0; m < 51; m++)
                                {
                                    password[3] = alphabet[m];
                                    if (strcmp(crypt(password, salt), hash) == 0)
                                    {
                                        printf("%s\n", password);
                                        return 0;
                                    }
                                    // loop for fifth char
                                    if (i > 3)
                                    {
                                        for (int n = 0; n <= 51; n++)
                                        {
                                            password[4] = alphabet[n];
                                            if (strcmp(hash, crypt(password, salt)) == 0)

                                            {
                                                printf("%s\n", password);
                                                return 0;
                                            }
                                        }
                                    }
                                }
                            }

                        }
                    }
                }
            }
        }

    }
    printf("crack failed\n");
}

