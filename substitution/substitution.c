#define _GNU_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    int len = strlen(key);
    bool correctLength = (len == 3); // demo with 3 first
    // check num of args and length
    if (argc == 2 && correctLength)
    {
        for (int i = 0; i < len; i++)
        {
            int onlyAlpha = isalpha(key[i]); // returns>0 if all alphabets
            string letter = (string) key[i];
            key[i] = ' ';
            char substring = strstr(key, letter);
            if (substring)
            {
                printf("%c\n", key[i]);
            }
        }
    }
}