// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <math.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// 200 number of buckets in hash table
const unsigned int N = 145000;

// tracks dictionary size
int dict_size = 0;

// base hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);
    node *p = table[hash_value];
    while (p != NULL)
    {
        if (strcasecmp(p->word, word) == 0)
        {
            return true;
        }
        // reassign p to the next word
        p = p->next;

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int len = strlen(word);
    __uint128_t hash_value = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(word[i]) || word[i] == 44)
        {
            int ascii_value = tolower(word[i]);
            // sum of ascii value * base value raise  to power of index
            // e.g. 'c' * 7^0 + 'a' * 7^1 + 't' * 7^2
            hash_value += ascii_value * (pow(7, i)); // polynomial hash, using base value of 7.
        }
    }
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
// hash table of some kind
bool load(const char *dictionary)
{
    char letter;
    FILE *txt_dict = fopen(dictionary, "r");
    if (txt_dict == NULL)
    {
        return false;
    }
    else
    {
        // parse through entire txt char by char until null
        fread(&letter, sizeof(char), 1, txt_dict);
        int letter_count = 0;
        while (letter != 0) // != null
        {
            char one_word[LENGTH + 1];
            while (letter != 10) // != \n
            {
                one_word[letter_count] = letter;
                letter_count += fread(&letter, sizeof(char), 1, txt_dict);
            }
            node *w = malloc(sizeof(node));
            if (w == NULL)
            {
                return false;
            }
            strcpy(w->word, one_word);
            int hash_value = hash(one_word);
            w->next = table[hash_value]; // point node to head of bucket
            table[hash_value] = w; // insert new node
            fread(&letter, sizeof(char), 1, txt_dict);
            memset(one_word, 0, (LENGTH + 1) * sizeof(char)); // resets all items in one_word array to NULL
            letter_count = 0;
            dict_size++;

            // check if EOF
            // two \n is EOF
            int counter = 1;
            if (letter == 10) // == \n
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
        fclose(txt_dict);
        return true;
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *hash_row = table[i];
        while (hash_row != NULL)
        {
            node *tmp = hash_row;
            hash_row = hash_row->next;
            free(tmp);
        }
        if (hash_row == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
