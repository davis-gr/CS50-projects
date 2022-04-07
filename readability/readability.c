#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    string fullText = get_string("Text: ");
    printf("%s\n", fullText);
    int letterCount = count_letters(fullText);
    printf("%i letters\n", letterCount);
    int wordCount = count_words(fullText);
    printf("%i words\n", wordCount);
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int c = text[i];
        if (isalpha(c))
            {
                count++;
            }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int c = text[i];
        if (isspace(c))
            {
                count++;
            }
    }
    //Treat for the last word of the text - it won't have whitespace after so it won't be counted in by the algo above.
    count++;
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int c = text[i];
        if (isspace(c))
            {
                count++;
            }
    }
    return count;
}