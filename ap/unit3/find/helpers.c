// Helper functions
#include <cs50.h>
#include <string.h>
#include "helpers.h"

// Returns true if value is in array of n values, else false
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int start = 0;
    int middle = n / 2;
    int end = n + 1;
    int length = n + 1;
    while (length > 0)
    {
        if (values[middle] == value)
        {
            // check if number found
            return true;
        }
        else if (values[middle] > value)
        {
            // search left
            end = middle;
            middle = (end - start) / 2;
        }
        else if (values[middle] < value)
        {
            // search right
            start = middle;
            middle = end - (start / 2);
        }
        length /= 2;
    }
    return false;
}

// Sorts array of n values
void sort(int values[], int n)
{
    // array stores count of each int
    int counting[65536] = {0};

    // count occurrences of each number
    for (int i = 0; i < n; i++)
    {
        counting[values[i]]++;
    }
    // insert numbers back into array sequentially
    for (long i = 0, j = 0; i < 65536; i++)
    {
        while (counting[i] > 0)
        {
            values[j] = i;
            // increment index to re-insert
            j++;
            // decrement counting array (prevent segmentation fault problem)
            counting[i]--;
        }
    }
    return;
}
