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
const unsigned int N = 26;

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
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
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
        fclose(inptr);
        return false;
    }
    // Read strings one at a time
    char *buffer[LENGTH + 1];
    while (fscanf(inptr, "%s", *buffer) != EOF)
    {
        // Create new no;de for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, *buffer);
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
        if (table[i] == NULL)
        {
            return false;
        }
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
return true;
}