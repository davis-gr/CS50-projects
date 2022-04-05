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
        long thirteen = 1000000000000;
        long fourteen = 10000000000000;
        long fifteen = 100000000000000;
        long sixteen = 1000000000000000;
        if (sum % 10 != 0 || counter < 14 || counter > 17)
        {
            printf("INVALID\n");
        }
        else if ((counter == 17 && credNumberOrig / sixteen == 4) || (counter == 14 && credNumberOrig / thirteen == 4))
        {
            printf("VISA\n");
        }
        else if (counter == 16 && credNumberOrig / fifteen == 3 && (credNumberOrig / fourteen == 4 || credNumberOrig / fourteen == 7) )
        printf("%i\n", sumEven);
        printf("%i\n", sumOdd);
        printf("%i\n", sum);
        printf("%i\n", counter);
        printf("%li\n", credNumberOrig / sixteen);
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