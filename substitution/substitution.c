#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string encrypt(string text);

string cipher = "";

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Enter a key and only one key!\n");
        return 1;
    }
    cipher = argv[1];
    if (strlen(cipher) < 26)
    {
        printf("Enter a key of exactly 26 letters!\n");
        return 1;
    }
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
        if (islower(text[i]) && isalpha(text[i]))
        {
            char newChar = tolower(cipher[charNum - 'a']);
            newtext[i] = newChar;
        }
        else if (isupper(text[i]) && isalpha(text[i]))
        {
            char newChar = toupper(cipher[charNum - 'A']);
            newtext[i] = newChar;
        }
    }
    return newtext;
}

// get key
// validate key