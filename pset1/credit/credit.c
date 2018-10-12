#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

// get user input for ccnumber
{
    long long creditCard;

    do
    {
        creditCard = get_long_long("Input your credit card number: ");
    }
    while (creditCard <= 0);

// get length of cc number
    int ccLength = 0;
    long long ccLengthChecker = creditCard;
    do
    {
        ccLengthChecker = ccLengthChecker / 10;
        ccLength++;
    }
    while (ccLengthChecker > 0);

//length validation
    if (ccLength != 13 && ccLength != 15 && ccLength != 16)
    {
        printf("INVALID\n");
    }

// starting with second to last digit - multiply every other digit by 2
    int sumDoubled = 0;
    int digitDoubled = 0;
    long multiplier = 10;
    for (int i = 0; i < (ccLength / 2); i++)
    {
        digitDoubled = (creditCard / multiplier % 10) * 2;
        if (digitDoubled >= 10)
        {
            sumDoubled += digitDoubled % 10;
            sumDoubled += digitDoubled / 10;
        }
        else
        {
            sumDoubled += digitDoubled;
        }

        multiplier *= 100;
    }
// get sum of digits not multiplied by 2
    int sumNotDoubled = 0;
    multiplier = 1;
    // length + 1 check only work with odd numbers?
    for (int i = 0; i < (ccLength / 2) + 1; i++)
    {
        sumNotDoubled += (creditCard / multiplier) % 10;
        multiplier *= 100;
    }
// add that sum to the sum of digits not multiplied by 2
    int checkSum = sumNotDoubled + sumDoubled;
//if last digit isn't 0, number is invalid.
    if (checkSum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        // American express check
        if (ccLength == 15)
        {
            int amex = creditCard / 10000000000000;
            if (amex == 34 || amex == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
            // Visa 13 digit check
        }
        else if (ccLength == 13)
        {
            int visa = creditCard / 100000000000;
            if (visa == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (ccLength == 16)
        {
            // Mastercard check
            int mastercard = creditCard / 100000000000000;
            if (mastercard >= 51 && mastercard <= 55)
            {
                printf("MASTERCARD\n");
            }
            else if (mastercard / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

    }

}