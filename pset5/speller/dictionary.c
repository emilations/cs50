// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <cs50.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Global variable shared with Loads and Size programs
int wordcount = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *cursor = NULL;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (!(cursor == NULL))
        {
            if (strcasecmp(word, cursor->word) == 0)
            {
                return true;
            }
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    int wordLength = strlen(word);
    for (int i = 0; i < wordLength / 3 ; i++)
    {
        sum += (word[i]);
    }
    int index = sum % N;
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary as given in the function input
    FILE *file = fopen(dictionary, "r");

    // Check if file openned sucessfully
    if (file == NULL)
    {
        printf("The dictionary file could not be opened. Load program returns 1 and exits.\n");
        return false;
    }

    // Initializing variables for hash table
    char word[LENGTH + 1];
    unsigned int index = 0;
    node *n = NULL;
    int wordLength = 0;

    // Read from the file and insert into hash table
    while (((fgets(word, 60, file))) && !(index == N))
    {
        // remove the space from the end of string word
        wordLength = strlen(word);
        word[wordLength - 1] = '\0';
        word[wordLength] = 0;
        index = hash(word);
        n = malloc(sizeof(node));
        // Check if malloc was successful
        if (n == NULL)
        {
            printf("Error: Malloc was not successful in the load program");
            return false;
        }
        n->next = NULL;
        strcpy(n->word, word);
        n->next = table[index];
        table[index] = n;
        wordcount++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (wordcount > 0)
    {
        return wordcount;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int index = 0;
    node *cursor = NULL;
    node *temp = NULL;
    for (int i = 0; i < N; i++)
    {
        index = i;
        cursor = table[i];
        while (cursor)
        {
            temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    if ((index == (N - 1)) && (cursor == NULL))
    {
        return true;
    }
    return false;
}