#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// fits spec for more and for less
int main(void)
{
    // get user input - problem spec asks for blank get_string function - otherwise would've included a prompt message
    string name = get_string();
    // initialise boolean to check for first char in name
    bool space = true;
    for (int i = 0; i < strlen(name); i++)
    {
        // check for space as gap between names - checks for punctuation too for edge cases mentioned but not asked for
        if (name[i] == ' ' || name[i] == "'" || name[i] == '-' || name[i] == '.')
        {
            space = true;
        }
        else if (isalpha(name[i]))
        {
            // if the last char was a space - detects char to add as initial.
            if (space == true)
            {
                printf("%c", toupper(name[i]));
                space = false;
            }
        }
    }
    // newline
    printf("\n");

}