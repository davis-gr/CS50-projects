#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string encrypt(string text);

int main(int argc, string argv[])
{
    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt(plaintext);
    string cipher = argv[];
    printf("%s", ciphertext);
}

string encrypt(string text)
{
    string newtext = text;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int charNum = tolower(text[i]);
        //printf("%i", tolower(charNum));
        char newChar = argv[charNum - 97];
        //printf(" - %i", pts);
        //printf("\n");
        if (charNum >= 97 && charNum <= 122)
        {
            newtext[i] = newChar;
        }
    }
//    printf("%i", totalPts);
//    printf("\n");
    return newtext;
}


// get key
// validate key
// get plaintext
// encipher
// print ciphertext