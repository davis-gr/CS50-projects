#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    // Reject anything else besides numbers between 1 and 8
    while (n < 1 || n > 8);
}