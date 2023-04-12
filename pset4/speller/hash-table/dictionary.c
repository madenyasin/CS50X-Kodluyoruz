// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node* create_node(char* value);
void destroy(node* head);

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // TODO

        node* new_node = create_node(word);
        if (!new_node)
        {
            unload();
            return false;
        }
        new_node->next = hashtable[hash(word)];
        hashtable[hash(word)] = new_node;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        for(node* travel = hashtable[i]; travel != NULL; travel = travel->next)
        {
            counter++;
        }
    }
    return counter;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO

    node* cursor = hashtable[hash(word)];
    while (cursor != NULL)
    {
        // parametredeki değer sözlükte varsa return true
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false; // parametredeki değer sözlükte yoksa return false
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    for (int i = 0; i < N; i++)
    {
        destroy(hashtable[i]); //destroy linked lists
        hashtable[i] = NULL; // dizinin her elemanını NULL olarak ayarla
    }
    return true;
}

// linked list functions

node* create_node(char* value)
{
    node* new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL)
    {
        return NULL;
    }
    // new_node->word = value;
    strcpy(new_node->word, value);
    new_node->next = NULL;
    return new_node;
}

void destroy(node* head)
{
    node* travel = head;
    if (!travel)
    {
        return;
    }
    destroy(travel->next);
    free(travel);
}