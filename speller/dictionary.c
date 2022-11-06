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
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

node create_word(char one_word[], int letter_count)
{
    node *w = malloc(sizeof(node));
    int index = one_word[letter_count - 1] - 97;
    w->word[index] = one_word[letter_count - 1];

    if (letter_count > 1)
    {
        create_word(one_word, letter_count - 1);
    }
    else
    {
        w->next = NULL;
        return *w;
    }
    return *w;
}

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
        int beginning_of_word = 1;
        // parse through txt until null
        int i = 0;
        int letter_count = 0;
        while (letter != 0) // != null
        {
            char one_word[LENGTH];
            while (letter != 10)
            {
                one_word[i] = letter;
                letter_count = fread(&letter, sizeof(char), 1, txt_dict);
                i++;
                letter_count++;
            }
            for (int j = 0; j < letter_count; j++)
            {
                node word = create_word(one_word, letter_count);
                if (j == letter_count -1)
                {
                    table[letter_count - 1] = *word; // -1 to get index 0
                }
            }
        }
            // node *tmp_one = malloc(sizeof(node));
            // node *tmp_two = malloc(sizeof(node));
            // node *w = malloc(sizeof(node));
            // int letter_count = 0;
            // // loop until end of word
            // while (letter != 10) // != \n
            // {
            //     if (letter != 44) // not '
            //     {
            //         letter = tolower(letter);
            //         if (beginning_of_word == 1)
            //         {
            //             w->word[letter - 97] = letter;
            //             beginning_of_word = 0;
            //             fread(&letter, sizeof(char), 1, txt_dict);
            //             w->next = tmp_one;
            //             letter_count++;
            //             continue;
            //         }
            //         tmp_one->word[letter - 97] = letter;
            //         // node *tmp_two = malloc(sizeof(node));
            //         tmp_one->next = tmp_two;
            //         tmp_one = tmp_two;
            //         letter_count++;

            //     }
            //     else if (letter == 44)
            //     {
            //         tmp_one->word[27] = letter;
            //         // node *tmp_two = malloc(sizeof(node));
            //         tmp_one->next = tmp_two;
            //         tmp_one = tmp_two;
            //         letter_count++;
            //     }
            //     // read next letter
            //     fread(&letter, sizeof(char), 1, txt_dict);
            // }
            // if (letter == 10)
            // {
            //     tmp_two->next = NULL;
            // }
            // table[letter_count - 1] = w; // 1 letter word at index 0
            // letter_count = 0;
            // // read next word
            // fread(&letter, sizeof(char), 1, txt_dict);
            // beginning_of_word = 1;
        // }
        // return true;
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
