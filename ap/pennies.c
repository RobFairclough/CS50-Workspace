#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int days = 0;
    long long pennies = 0;
    do
    {
        days = get_int("Days in month: ");
    }
    while (days > 31 || days < 28);

    do
    {
        pennies = get_long_long("Pennies on first day: ");
    }
    while (pennies < 1);
    pennies *= pow(2, days);
    printf("$%lld.%lld", (pennies / 100), (pennies % 100));

}