#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // get isbn
    long long isbn = get_long_long("ISBN: ");
    // initialise sum to hold digits multiplied
    int checksum = 0;
    // get last digit to check
    int checkdigit = isbn % 10;
    // remove last digit to loop through rest
    isbn /= 10;
    for (int i = 0, j = 9; i < 9; i++)
    {
        int digit = isbn % 10;
        checksum += (digit * j);
        isbn /= 10;
        j--;
    }
    if (checksum % 11 == checkdigit)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}