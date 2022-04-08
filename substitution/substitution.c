#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string encrypt(string text);

string cipher = "";

int main(int argc, string argv[])
{
    //Handles too many or too few command line arguments
    if (argc != 2)
    {
        printf("Enter a key and only one key!\n");
        return 1;
    }
    //cipher holds the key from command line
    cipher = argv[1];

    //handles too short keys
    if (strlen(cipher) < 26)
    {
        printf("Enter a key of exactly 26 unique English letters!\n");
        return 1;
    }
    for (int i = 0, n = strlen(cipher); i < n; i++)
    {
        //this tolower part handles upper and lower case duplicates (e.g. A & a)
        int singleLetterI = tolower(cipher[i]);
        //handles non-alpha characters
        if (isalpha(cipher[i]) == 0)
        {
            printf("Enter a key of exactly 26 unique English letters!\n");
            return 1;
        }
        for (int j = i + 1; j < strlen(cipher); j++)
        {
            int singleLetterJ = tolower(cipher[j]);
            // handles duplicate characters
            if (singleLetterI == singleLetterJ)
            {
                printf("Enter a key of exactly 26 unique English letters!\n");
                return 1;
            }
        }
    }
    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt(plaintext);
    printf("ciphertext: %s\n", ciphertext);
}

string encrypt(string text)
{
    string newtext = text;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int charNum = text[i];
        //handles lower case alpha text replacement
        if (islower(text[i]) && isalpha(text[i]))
        {
            char newChar = tolower(cipher[charNum - 'a']);
            newtext[i] = newChar;
        }
        //handles upper case alpha text replacement
        else if (isupper(text[i]) && isalpha(text[i]))
        {
            char newChar = toupper(cipher[charNum - 'A']);
            newtext[i] = newChar;
        }
    }
    return newtext;
}