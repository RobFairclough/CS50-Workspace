#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    // check for correct number of command line args
    if (argc != 4)
    {
        printf("argument error\n");
        return 1;
    }
    // store and format arguments as variables
    float first = atof(argv[1]);
    char mod = argv[2][0];
    float second = atof(argv[3]);
    // multiply
    if (mod == 'x')
    {
        printf("%f", (first * second));
    }
    // divide
    else if (mod == '/')
    {
        printf("%f", (first / second));
    }
    // add
    else if (mod == '+')
    {
        printf("%f", (first + second));
    }
    // subtract
    else if (mod == '-')
    {
        printf("%f", (first - second));
    }
    // modulus
    else if (mod == '%')
    {
        int q = first / second;
        printf("%f", (first - (second * q)));
    }
    else
    {
        printf("mod error");
        return 1;
    }
    printf("\n");
}