#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string encrypt(string text);

string cipher = "";

int main(int argc, string argv[])
{
    string plaintext = get_string("plaintext: ");
    cipher = argv[1];
    printf("%s\n", cipher);
    string ciphertext = encrypt(plaintext);
    printf("%s\n", ciphertext);
}

string encrypt(string text)
{
    string newtext = text;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int charNum = tolower(text[i]);
        //printf("%i", tolower(charNum));
        char newChar = cipher[charNum - 97];
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