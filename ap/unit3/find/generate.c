// Generates pseudorandom numbers in [0,LIMIT), one per line

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // ensure correct number of arguments entered
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // convert first arg from default string to integer
    int n = atoi(argv[1]);

    // seed random number gen with second arg, converted to integer as above
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    // seed random with NULL
    else
    {
        srand48((long int) time(NULL));
    }

    // Loop n times, printing a random number below upper limit each loop
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // Success
    return 0;
}