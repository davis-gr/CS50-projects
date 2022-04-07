#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    string fullText = get_string("Text: ");
    printf("%s\n", fullText);
    int letterCount = count_letters(fullText);
    printf("%i letters\n", letterCount);
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int charNum = tolower(text[i]);
        if (charNum >= 97 && charNum <= 122)
            {
                count++;
            }
    }
    return count;
}