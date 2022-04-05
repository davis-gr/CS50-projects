#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long n;
    int n2, n3;
    //do
    {
        n = get_long("Number: ");
        n2 = n % 100;
        n3 = n2 % 10;
    }
    // Reject anything else besides numbers between 1 and 8
    // Amex - 15 digits, starts with 34 or 37
    // MC - 16 digits, starts with 51-55
    // VISA - 13 or 16 digits, starts with 4
    //while (strlen(n) < 13);
    {
        printf("%li\n", n);
        printf("%i\n", n2);
        printf("%i\n", n3);
    }

}