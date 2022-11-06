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

// hash table for 26 letters + 1 apostrope
node *alpha_apost[27];

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

// // 26 prime numbers in ascending order
// int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

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
    // char filename[strlen(dictionary) + 4];
    // sprintf(filename, "%s.txt", dictionary);
    char letter;
    FILE *txt_dict = fopen(dictionary, "r");
    if (txt_dict != NULL)
    {
        fread(&letter, sizeof(char), 1, txt_dict);
        node *w = malloc(sizeof(node));
        node *tmp_one = malloc(sizeof(node));
        // node *tmp_two = malloc(sizeof(node));
        int beginning_of_word = 1;
        // parse through txt until null
        while (letter != 0) // != null
        {
            int letter_count = 0;
            // loop until end of word
            while (letter != 10) // != \n
            {
                if (letter != 44) // not '
                {
                    letter = tolower(letter);
                    if (beginning_of_word == 1)
                    {
                        w->word[letter - 97] = letter;
                        beginning_of_word = 0;
                        fread(&letter, sizeof(char), 1, txt_dict);
                        w->next = tmp_one;

                        letter_count++;
                        continue;
                    }
                    tmp_one->word[letter - 97] = letter;
                    node *tmp_two = malloc(sizeof(node));
                    tmp_one->next = tmp_two;
                    tmp_one = tmp_two;
                    letter_count++;

                }
                else if (letter == 44)
                {
                    w->word[27] = letter;
                }
                else if (letter == 10)
                {
                    break;
                }
                // read next letter
                fread(&letter, sizeof(char), 1, txt_dict);
            }

            table[letter_count - 1] = w; // 1 letter word at index 0
            letter_count = 0;
            // read next word
            fread(&letter, sizeof(char), 1, txt_dict);
        }
        return true;
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
