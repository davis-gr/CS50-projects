#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long credNumber;
    {
        credNumber = get_long("Number: ");
    }
    {
        int counter = 1;
        int sumEven = 0;
        int sumOdd = 0;
        int sum = 0;
        long credNumberOrig = credNumber;
        while (credNumber > 0)
        {
            int x = credNumber % 10;
            credNumber = credNumber / 10;
            if (counter % 2 == 0)
            {
                x = x * 2;
                while (x > 0)
                {
                    int y = x % 10;
                    x = x / 10;
                    sumEven = sumEven + y;
                }
            }
            else
            {
                sumOdd = sumOdd + x;
            }
            sum = sumOdd + sumEven;
            counter++;
        }
        if (sum % 10 != 0 || counter < 14 || counter > 17)
        {
            printf("INVALID\n");
        }
        else if (counter == 17 && credNumberOrig / 1000000000000000)
        {
            printf("VISA\n");
        }
        printf("%i\n", sumEven);
        printf("%i\n", sumOdd);
        printf("%i\n", sum);
        printf("%i\n", counter);
        printf("%li\n", credNumberOrig / 1000000000000000);
    }
}


    // Amex - 15 digits, starts with 34 or 37
    // MC - 16 digits, starts with 51-55
    // VISA - 13 or 16 digits, starts with 4
    //while (strlen(n) < 13);
//todo
//input
//checksum
//check length and starting digits
//print result