#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string encrypt(string text);

string cipher = "";

int main(int argc, string argv[])
{
    cipher = argv[1];
    string plaintext = get_string("plaintext: ");
    printf("%s\n", cipher);
    string ciphertext = encrypt(plaintext);
    printf("ciphertext: %s\n", ciphertext);
}

string encrypt(string text)
{
    string newtext = text;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int charNum = text[i];
        //printf("%i", tolower(charNum));
        if (islower(text[i]))
        {
            char newChar = cipher[charNum - 'a'];
        }
        else if (isupper(text[i]))
        {
            char newChar = cipher[charNum - 'A'];
        }
        //printf(" - %i", pts);
        //printf("\n");
        if isalpha(charNum)
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