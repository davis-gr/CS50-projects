#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long credNumber, i;
    //do
    {
        credNumber = get_long("Number: ");
        //n2 = n % 10;
        //n3 = n % 100 / 10 % 10;
        //n4 = n % 1000 / 100 % 100;
    }
    // Amex - 15 digits, starts with 34 or 37
    // MC - 16 digits, starts with 51-55
    // VISA - 13 or 16 digits, starts with 4
    //while (strlen(n) < 13);
    {
        for (i = 1; i <= 16; i++))
            {
                for (long n = 10, )
            }

        printf("%li\n", n);
        printf("%li\n", n2);
        printf("%li\n", n3);
        printf("%li\n", n4);
    }

}

//todo
//input
//checksum
//check length and starting digits
//print result