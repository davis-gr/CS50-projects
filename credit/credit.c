#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n;
    long n_length;
    //do
    {
        n = get_long("Number: ");
        n_length = n % 100;
    }
    // Reject anything else besides numbers between 1 and 8
    // Amex - 15 digits, starts with 34 or 37
    // MC - 16 digits, starts with 51-55
    // VISA - 13 or 16 digits, starts with 4
    //while (strlen(n) < 13);
    {
        printf("%li\n", n);
        printf("%li\n", n_length);

    }

}