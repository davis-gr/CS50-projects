// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 11881376;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hvalue = hash(word);
    //Access linked list at that index in the hash table
    for (node *tmp = table[hvalue]; tmp != NULL; tmp = tmp->next)
    {
        //Traverse linked list, looking for the word (strcasecmp)
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
// assign first 5 letters into separate buckets, after that performance improvement is marginal, but memory is huge
    int h = 0;
    int n = 26;
    if (strlen(word) < 2 || isalpha(word[1]) == 0)
    {
        h = toupper(word[0]) - 'A';
    }
    else if (strlen(word) < 3 || isalpha(word[2]) == 0)
    {
        h = (toupper(word[0]) - 'A') * n + (toupper(word[1]) - 'A');
    }
    else if (strlen(word) < 4 || isalpha(word[3]) == 0)
    {
        h = (toupper(word[0]) - 'A') * n * n  + (toupper(word[1]) - 'A') * n + (toupper(word[2]) - 'A');
    }
    else if (strlen(word) < 5 || isalpha(word[4]) == 0)
    {
        h = (toupper(word[0]) - 'A') * n * n * n + (toupper(word[1]) - 'A') * n * n + (toupper(word[2]) - 'A') * n +
            (toupper(word[3]) - 'A');
    }
    else
    {
        h = (toupper(word[0]) - 'A') * n * n * n * n + (toupper(word[1]) - 'A') * n * n * n + (toupper(word[2]) - 'A') * n * n +
            (toupper(word[3]) - 'A') * n + (toupper(word[4]) - 'A');
    }
    return h;
}
int wordCount = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open up dict file
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    // Read strings one at a time
    char buffer[LENGTH + 1];
    while (fscanf(inptr, "%s", buffer) != EOF)
    {
        // Create new no;de for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, buffer);
        // Hash word to obtain a hash value
        int hvalue = hash(n->word);
        // Insert node into hash table at that location
        if (table[hvalue] == NULL)
        {
            table[hvalue] = n;
            n->next = NULL;
        }
        else
        {
            n->next = table[hvalue]->next;
            table[hvalue]->next = n;
        }
        wordCount++;
    }
    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}