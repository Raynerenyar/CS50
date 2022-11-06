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
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// 26 prime numbers in ascending order
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

//
typedef struct
{
    int index;
    char word[LENGTH + 1];
}
hashedWord;

// Loads dictionary into memory, returning true if successful, else false
// hash table of some kind
bool load(const char *dictionary)
{
    // open and read file
    char filename[strlen(dictionary) + 4];
    sprintf(filename, "%s.txt", dictionary);
    FILE *txt_dict = fopen(filename, "r");

    if (txt_dict != NULL)
    {
        char word[LENGTH + 1];
        char letter = fread(&letter, sizeof(char), 1, txt_dict);
        int i = 0;
        while (letter != 0) // null
        {
            while (letter != 10) // \n
            {
                // append to string;
                word[i] = letter;
                i++;
                // read next char
                fread(&letter, sizeof(char), 1, txt_dict);
            }
            int len_of_word = LENGTH + 1;
            int hash = 0;
            hashedWord *hashed_word = malloc(sizeof(int) + sizeof(word[LENGTH + 1]));
            for (int j = 0; j < len_of_word; j++)
            {
                if (word[j] != 0)
                {
                    // polynomial hashing
                    hash += word[j] * prime[j];
                    hashed_word->word[j] = word[j];
                }
                else
                {
                    break;
                }
            }
            hashed_word->index = hash;
        }
    }
    return false;
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
