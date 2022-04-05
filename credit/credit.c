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
        int counter = 1;
        int sumEven = 0;
        while (credNumber > 0)
        {
            int x = credNumber % 10;
            printf("%i\n", x);
            credNumber = credNumber / 10;
            if (counter % 2 == 0)
            {
                int y = x * 2;
                while (y > 0)
                {
                    int z = y % 10;
                    z = z / 10;
                    sumEven = sumEven + z;
                }
            }
            counter++;
            printf("%i\n", sumEven);
        }

    }

}

//todo
//input
//checksum
//check length and starting digits
//print result