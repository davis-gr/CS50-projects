#include <cs50.h>
#include <stdio.h>

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
        if (sum % 10 == 0)
        {
            if ((counter == 17 && credNumberOrig / sixteen == 4) || (counter == 14 && credNumberOrig / thirteen == 4))
            {
                printf("VISA\n");
            }
            else if (counter == 16 && (credNumberOrig / fourteen == 34 || credNumberOrig / fourteen == 37))
            {
                printf("AMEX\n");
            }
            else if (counter == 17 && (credNumberOrig / fifteen == 51 || credNumberOrig / fifteen == 52 || credNumberOrig / fifteen == 53 || credNumberOrig / fifteen == 54 || credNumberOrig / fifteen == 55))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        printf("%i\n", sumEven);
        printf("%i\n", sumOdd);
        printf("%i\n", sum);
        printf("%i\n", counter);
        printf("%li\n", credNumberOrig / fifteen);
        printf("%li\n", credNumberOrig / fourteen);
    }
}
