// Helper functions for music
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "helpers.h"


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // Get first and second digit, divide to account for 1, 2, 4, 8 in second digit and multiply by 8 to get number of 1/8ths
    double first = atoi(&fraction[0]);
    double second = atoi(&fraction[2]);
    return (int)((first / second) * 8);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // initalise hertz at 440hz - A4.
    double hz = 440;
    // get note
    char n = note[0];
    // initialise accidental - won't be used unless an accidental is present
    bool accidental = false;
    char acc = note[1];
    // get octave
    int oct = atoi(&note[1]);

    // check for accidental
    if (note[1] == '#' || note[1] == 'b')
    {
        // adjust octave if accidental exists
        oct = atoi(&note[2]);
        accidental = true;
    }

    // adjust for octave
    if ((int) oct > 4)
    {
        hz = (hz * pow(2, ((double)oct - 4)));
    }
    else if (oct < 4)
    {
        hz = (hz / pow(2, ((double)4 - oct)));
    }

    // initialised at correct value for A

    // B
    if (n == 'B')
    {
        // set to B4
        hz = (hz * pow(2, ((double)2 / 12)));
    }

    //C
    if (n == 'C')
    {
        // set to C4
        hz = (hz / pow(2, ((double)9 / 12)));
    }

    //D
    if (n == 'D')
    {
        // set to D4
        hz = (hz / pow(2, ((double)7 / 12)));
    }

    // E
    if (n == 'E')
    {
        // set to E4
        hz = (hz / pow(2, ((double)5 / 12)));
    }

    // F
    if (n == 'F')
    {
        // set to F4
        hz = (hz / pow(2, ((double)4 / 12)));
    }

    // G
    if (n == 'G')
    {
        // set to G4
        hz = (hz / pow(2, ((double)2 / 12)));
    }

    // Accidentals - this should be below the other notes
    if (accidental == true)
    {
        if (acc == '#')
        {
            hz = (hz * pow(2, ((double)1 / 12)));
        }
        else if (acc == 'b')
        {
            hz = (hz / pow(2, ((double)1 / 12)));
        }
    }
    return round(hz);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // if line input is newline
    if (strcmp(s, "") == 0 || strcmp(s, "\n") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
