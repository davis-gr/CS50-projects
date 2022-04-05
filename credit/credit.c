#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credNumber;
    {
        // Prompt for credit card number
        credNumber = get_long("Number: ");
    }
    {
        // Define variables used for loops and checking credit card checksums
        int counter = 1;
        int sumEven = 0;
        int sumOdd = 0;
        int sum = 0;
        // Save original credit card number for identifying card type
        long credNumberOrig = credNumber;
        // Loop that goes through each credit card digit starting from the end
        while (credNumber > 0)
        {
            int x = credNumber % 10;
            credNumber = credNumber / 10;
            // Condition checks if this digit is "every 2nd digit", i.e. even digit
            if (counter % 2 == 0)
            {
                // Multiplies by 2 according to algorithm
                x = x * 2;
                while (x > 0)
                {
                    // Sums up the digits from these multiplied numbers
                    int y = x % 10;
                    x = x / 10;
                    sumEven = sumEven + y;
                }
            }
            else
            {
                // Sums up all odd digits in the card
                sumOdd = sumOdd + x;
            }
            // Sums up odd + even sum
            sum = sumOdd + sumEven;
            // Iterates to next digit
            counter++;
        }
        // Here I define variables for finding 1st/2nd digit of the card easily, depending on how many digits the card number has
        long thirteen = 1000000000000;
        long fourteen = 10000000000000;
        long fifteen = 100000000000000;
        long sixteen = 1000000000000000;
        // First check if the checksum is valid. Otherwise, an INVALID response is printed.
        if (sum % 10 == 0)
        {
            // It's pretty much self explanatory from here on - every card type has an algorithm by which the card can be identified. If the cards cannot be identified, then an INVALID response is printed.
            if ((counter == 17 && credNumberOrig / sixteen == 4) || (counter == 14 && credNumberOrig / thirteen == 4))
            {
                printf("VISA\n");
            }
            else if (counter == 16 && (credNumberOrig / fourteen == 34 || credNumberOrig / fourteen == 37))
            {
                printf("AMEX\n");
            }
            else if (counter == 17 && (credNumberOrig / fifteen == 51 || credNumberOrig / fifteen == 52 || credNumberOrig / fifteen == 53
                                       || credNumberOrig / fifteen == 54 || credNumberOrig / fifteen == 55))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}