#include <stdio.h>
#include <cs50.h>


int main(void)
{
    //gets name from x person
    string name = get_string("What's your name? ");

    //displays their name on the screen
    printf("hello, %s\n", name);
}
