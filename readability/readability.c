#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string fullText = get_string("Text: ");
//    printf("%s\n", fullText);
    int letterCount = count_letters(fullText);
//    printf("%i letters\n", letterCount);
    int wordCount = count_words(fullText);
//    printf("%i words\n", wordCount);
    int sentenceCount = count_sentences(fullText);
//    printf("%i sentences\n", sentenceCount);

    // L is the average number of letters per 100 words in the text
    float L = (float)letterCount / wordCount * 100.0;
//    printf("%f L \n", L);

    // S is the average number of sentences per 100 words in the text.
    float S = (float)sentenceCount / wordCount * 100.0;
//    printf("%f S \n", S);

    int index = round(0.0588 * L - 0.296 * S - 15.8);
//    printf("%i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %i", index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    printf("\n");
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
        if (c == 46 || c == 33 || c == 63)
            {
                count++;
            }
    }
    return count;
}