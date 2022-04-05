#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long credNumber;
    //do
    {
        credNumber = get_long("Number: ");
    }
    // Amex - 15 digits, starts with 34 or 37
    // MC - 16 digits, starts with 51-55
    // VISA - 13 or 16 digits, starts with 4
    //while (strlen(n) < 13);
    {
        while (credNumber > 0)
        {
            int x = credNumber % 10;
            printf("%li\n", credNumber);
            printf("%i\n", x);
            credNumber = credNumber / 10;
        }

    }

}

//todo
//input
//checksum
//check length and starting digits
//print result