#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int j = 1;
    int n;
    //this is making sure you're typing numbers between 1-8
    do
    {
        n = get_int("Height: ");
    }
    while(n < 1 || n > 8);
    //this is making each single role using loops
    for(int i = 0; i < n; i++)
    {
        j=i + 1;
        //you need x-height amount of free space each, so you use this
        while(j < n)
        {
            printf(" ");
            j++;
        }
        //loop for first pyramid
        for(int k = -1; k<i; k++)
        {
        printf("#");
        }
        //the space between them is flat
        printf("  ");
        //second pyramid
        for(int q = -1; q<i; q++)
        {
            printf("#");
        }
        printf("\n");

    }


}