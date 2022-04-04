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


    // For each row
    for (int i = 1; i <= n; i++)
    {
        //Add whitespaces at first
        for (int j = n - i; j > 0; j--)
        {
            printf(" ");
        }
        // Add as many hashes as necessary except last one
        for (int k = 1; k < i; k++)
        {
            printf("#");
        }
        // Add last hash and 2 whitespaces
        {
            printf("#  ");
        }
        // Add opposite side hashes according to how long the pyramid should be
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }
        // Add newline
        printf("\n");
    }
}