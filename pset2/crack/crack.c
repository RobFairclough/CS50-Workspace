#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
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


}

