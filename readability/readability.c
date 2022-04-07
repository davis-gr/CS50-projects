#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    string fullText = get_string("Text: ");
    printf("%s", fullText)
    printf("%i letters", letterCount)
}

int count_letters(string text)
{
    int letterCount = 0
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int charNum = tolower(text[i]);
        if (charNum >= 97 && charNum <= 122)
            {
                letterCount++
            }
    }
}