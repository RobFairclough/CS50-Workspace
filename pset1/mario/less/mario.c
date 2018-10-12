#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Do while loop to validate user input where get_int doesn't meet spec
    int height = 0;
    do
    {
        height = get_int("Enter height of half-pyramid: ");
    }
    while (height < 0 || height > 23);
    int hashes = 2;
    //int maxhash = height + 1;
    int spaces = height - 1;
    // Outer for loop runs once for each row
    for (int i = 0; i < height; i++)
    {
        // Inner for loop runs to print spaces
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        // Inner for loop runs to print hashes
        for (int j = 0; j < hashes; j++)
        {
            printf("#");
        }
        // Linebreak at end of each rpw
        printf("\n");
        spaces--;
        hashes++;
    }
}
//First row should have 2 * # following (max height - 1) spaces