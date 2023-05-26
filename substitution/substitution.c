#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool no_repeat(string code);

int main(int argc, string argv[])
{
    //checks if it has more than a single word after the prompt
    string code = argv[1];
    if (argv[2] != NULL)
    {
        printf("Enter a 26 letters key.\n");
        return 1;
    }
    //checks if the single word has 26 letters
    if (strlen(code) != 26)
    {
        printf("Type a valid key.\n");
        return 1;
    }
    //checks if the word has only actual letters
    for (int j = 0, q = strlen(code); j < q; j++)
    {
        if (isalpha(code[j]))
        {}
        else
        {
            printf("Type a valid key.\n");
            return 1;
        }
    }
    //checks if the word has repeated letters
    if (no_repeat(code))
    {}
    else
    {
        printf("Type a valid key.\n");
        return 1;
    }

    //gets the word to be encrypted from user
    string g = get_string("plaintext: ");

    //encrypts the word based on the key given to the program
    printf("ciphertext: ");
    for (int i = 0, x = strlen(g); i < x; i++)
    {
        if (g[i] > 64 && g[i] < 91)
        {
            //uppercase letters
            printf("%c", toupper(code[g[i] - 65]));
        }
        else if (g[i] > 96 && g[i] < 124)
        {
            //lowercase letters
            printf("%c", tolower(code[g[i] - 97]));
        }
        else
        {
            //everything else just gets repeated
            printf("%c", g[i]);
        }
    }
    printf("\n");
    return 0;
}

//the program to check repeated letters
bool no_repeat(string code)
{
    //chooses a letters
    for (int m = 0, n = strlen(code); m < n; m++)
    {
        for (int z = m + 1; z < n; z++)
        {
            //compares with every other single letter
            if (code[m] == code[z])
            {
                return false;
            }
        }
    }
    return true;
}