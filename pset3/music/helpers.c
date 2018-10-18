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
    // TODO
        //0 parse the string into a note and its octave
        //calculate the frequency of the note in the given octave (hz)
        //return the frequency as integer in hz
        // A4 = 440hz
        // for every semitone up, multiply frequency by 2 ^ 1/12
        // for every semitone down, divide frequency by 2 ^ 1/12
        // eg a#4 - 440 * (2 ^ 1/12) ~= 466
        // can multiply by (2 ^ 2, 3, 4/12 to do multiple semitones)
        // full octave is 440 * 2 ^ 12/12 ie 2 ^ 1, (440 * 2)
        // to go up an octave, multiply by 2
        // to go down an octave, divide by 2
        // applies to any octave, not just A4
        // note always a string
        // first char always the letter of the note
        // second char could be either accidental('#' or 'b') or an octave
        // third char optional but would always be octave
        // step 1 - implement octave of A
        // step 2 - support A#, Ab - to make sharp multiply by 2 ^ 1/12, to make flat divide by 2 ^ 1/12
        // be sure to support a# and Ab in multiple octave
        // step 3 - support all notes
        //  using A as starting point, figure out how many semitones away the current note is.
        // remember that octaves start at C (c5 is one semitone above b4)
        // make sure to round any decimals to nearest integer

        // IDEA - start with A4 - get value for the note relative to A4, multiply/divide by 2, 4, 8

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
            hz = round(hz * pow(2, ((double)oct - 4)));
        }
        else if (oct < 4)
        {
            hz = round(hz / pow(2, ((double)4 - oct)));
        }

        // A
        if (n == 'A')
        {

        }

        // B
        if (n == 'B')
        {
            // set to B4
            hz = round(hz * pow(2, ((double)2/12)));
        }

        //C
        if (n == 'C')
        {
            // set to C4
            hz = round(hz / pow(2, ((double)9/12)));
        }

        //D
        if (n == 'D')
        {
            // set to D4
            hz = round(hz / pow(2, ((double)7/12)));
        }

        // E
        if (n == 'E')
        {
            // set to E4
            hz = round(hz / pow(2, ((double)5/12)));
        }

        // F
        if (n == 'F')
        {
            // set to F4
            hz = round(hz / pow(2, ((double)4/12)));
        }

        // G
        if (n == 'G')
        {
            // set to G4
            hz = round(hz / pow(2, ((double)2/12)));
        }

        // Accidentals - this should be below the other notes
        if (accidental == true)
        {
            if (acc == '#')
            {
                hz = round(hz * pow(2, ((double)1/12)));
            }
            else if (acc == 'b')
            {
                hz = round(hz / pow(2, ((double)1/12)));
            }
        }
        return hz;

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
