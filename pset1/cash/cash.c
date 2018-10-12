#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Number of coins to return
    int coins = 0;
    // Stores amount of change owed
    int change = 0;
    // Validates input of change as float type and non-negative, multiplies by 100 to prevent imprecision errors from floating point
    do
    {
        change = round(get_float("How much change are you owed? ") * 100);
    }
    while (change < 0);
    // Each check increments coins every time they're required and deducts value of coin from remainder
    // Checks against quarter
    while (change >= 25)
    {
        coins++;
        change -= 25;
    }
    // Checks against dime
    while (change >= 10)
    {
        coins ++;
        change -= 10;
    }
    // Checks against nickel
    while (change >= 5)
    {
        coins++;
        change -= 5;
    }
    // Checks against penny
    while (change >= 1)
    {
        coins++;
        change -= 1;
    }
    printf("%i\n", coins);
}