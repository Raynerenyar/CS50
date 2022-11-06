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
    char filename[strlen(dictionary) + 4];
    sprintf(filename, "%s.txt", dictionary);
    FILE *txt_dict = fopen(filename, "r");
    if (txt_dict != NULL)
    {
        char letter = fread(&letter, sizeof(char), 1, txt_dict);
        node *w = malloc(sizeof(node));
        node *tmp_one = malloc(sizeof(node));
        node *tmp_two = malloc(sizeof(node));
        int beginning_of_word = 1;
        while (letter != 0 && letter != 10) // != null and != \n
        {
            if (letter != 44) // not '
            {
                letter = tolower(letter);
                if (beginning_of_word == 1)
                {
                    w->word[letter - 61] = letter;
                    // table[letter-61] = w; // minus 61 to get index
                    beginning_of_word = 0;
                    letter = fread(&letter, sizeof(char), 1, txt_dict);
                    *tmp_one = *w;
                    continue;
                }
                w->next = tmp_one;
                tmp_one->word[letter - 61] = letter;
                *tmp_one = *w;

            }
            else if (letter == 44)
            {
                w->word[27] = letter;
            }
            letter = fread(&letter, sizeof(char), 1, txt_dict);
        }
        // // count num of words
        // int word_count = 0;
        // char letter = fread(&letter, sizeof(char), 1, txt_dict);
        // while (letter != 0)
        // {
        //     if (letter != 10)
        //     {
        //         word_count++;
        //     }
        //     letter = fread(&letter, sizeof(char), 1, txt_dict);
        // }
        // fclose(txt_dict);
        // hashedWord dictionary_of_words[word_count];
        // // *dictionary_of_words = malloc(word_count * sizeof(hashedWord));
        // // reopen txt file
        // FILE *dict = fopen(filename, "r");
        // letter = fread(&letter, sizeof(char), 1, dict);
        // char word[LENGTH + 1];
        // int i = 0;
        // while (letter != 0) // != null
        // {
        //     while (letter != 10) // != \n
        //     {
        //         // append to string;
        //         word[i] = letter;
        //         i++;
        //     }
        //     int len_of_word = LENGTH + 1;
        //     int hash = 0;
        //     hashedWord *hashed_word = malloc(sizeof(int) + sizeof(word[LENGTH + 1]));
        //     for (int j = 0; j < len_of_word; j++)
        //     {
        //         if (word[j] != 0)
        //         {
        //             // polynomial hashing
        //             hash += word[j] * prime[j];
        //             hashed_word->word[j] = word[j];
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        //     hashed_word->index = hash;
        //     // read next char
        //     letter = fread(&letter, sizeof(char), 1, dict);
        // }
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
