#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string paragraph = get_string("Text: ");
    //doing in a single float makes it work
    //l= letters/words * 100
    //s= sentences/words * 100
    //this checks the grade level defined by the Coleman-Liau index
    float index = 0.0588 * count_letters(paragraph) / count_words(paragraph) * 100 - 0.296 * count_sentences(paragraph) / count_words(
                      paragraph) * 100 - 15.8;
    //clear if is 16+
    if (round(index) >= 16)
    {
        printf("Grade 16+");
    }
    //checks if it is bellor first grade
    else if (round(index) < 1)
    {
        printf("Before Grade 1");
    }
    //prints the exact grade like the prompt
    else
    {
        printf("Grade %i", (int) round(index));
    }
    printf("\n");
}
//makes everything uppercase and counts every single letter
int count_letters(string text)
{
    int letters = 0;
    for (int k = 0, x = strlen(text); k < x; k++)
    {
        if (toupper(text[k]) < 91 && toupper(text[k]) > 64)
        {
            letters++;
        }
    }
    return letters;
}
//calculates number of words by chekin how many spaces there are
int count_words(string text)
{
    int words = 1;
    for (int j = 0, x = strlen(text); j < x; j++)
    {
        if (text[j] == 32)
        {
            words++;
        }
    }
    return words;
}
//calculates number of sentences based on how many !/?/. there are
int count_sentences(string text)
{
    int senteces = 0;
    for (int i = 0, x = strlen(text); i < x; i++)
    {
        if (text[i] == 33)
        {
            senteces++;
        }
        else if (text[i] == 46)
        {
            senteces++;
        }
        else if (text[i] == 63)
        {
            senteces++;
        }
    }
    return senteces;
}