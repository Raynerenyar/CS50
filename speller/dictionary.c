// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
// 1 to 45 in length
const unsigned int N = LENGTH;

// base hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int i = 0;
    int letter_count = 0;
    char indices[LENGTH];
    unsigned int index = hash(word[i]);
    while (index != 0)
    {
        indices[i] = index;
        letter_count++;
    }
    for (int j = 0; j < letter_count; j++)
    {
        node t = table[letter_count].word[j];
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

node *create_word(char one_word[], int letter_count, int letter_index)
{
    node *w = malloc(sizeof(node));
    int index = one_word[letter_index] - 97;
    if (letter_count > 1)
    {
        node *next_word = create_word(one_word, letter_count - 1, letter_index + 1);
        w->word[index] = one_word[letter_index];
        w->next = next_word;
    }
    else
    {
        w->word[index] = one_word[letter_index];
        w->next = NULL;
        return w;
    }
    return w;
}

// Loads dictionary into memory, returning true if successful, else false
// hash table of some kind
bool load(const char *dictionary)
{
    char letter;
    FILE *txt_dict = fopen(dictionary, "r");
    if (txt_dict != NULL)
    {
        fread(&letter, sizeof(char), 1, txt_dict);
        int beginning_of_word = 1;
        // parse through txt until null
        int letter_count = 0;
        while (letter != 0) // != null
        {
            char one_word[LENGTH];
            while (letter != 10) // != \n
            {
                one_word[letter_count] = letter;
                letter_count += fread(&letter, sizeof(char), 1, txt_dict);
            }
            int start = 0;
            node *word = create_word(one_word, letter_count, start);
            table[letter_count - 1] = word; // -1 to get index 0
            letter_count = 0;
            fread(&letter, sizeof(char), 1, txt_dict);
            int counter = 1;
            if (letter == 10)
            {
                counter++;
                if (counter == 2)
                {
                    break;
                }
                else
                {
                    counter = 0;
                    continue;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
