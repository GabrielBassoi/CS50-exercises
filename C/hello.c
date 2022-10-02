#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //question----------------------------------------
    string name = get_string("What's your name? ");
    //Hello, (name)-----------------------------------
    printf("hello, %s\n", name);
}