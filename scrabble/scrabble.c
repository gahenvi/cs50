#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //deciding the winner based on the amount of points
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    int x = strlen(word);
    for (int i = 0; i < x; i++)
    {
        if (toupper(word[i]) < 65 || toupper(word[i]) > 90)
        {
            //blank
        }
        else
        {
            //is making everything uppercase so it can use 65 as a messure for points and adding it to score
            score = score + POINTS[toupper(word[i]) - 65];
        }
    }
    return score;

}
