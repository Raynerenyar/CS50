#define _GNU_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool isSubstring(string text, char letter);

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
            char letter = key[i];
            key[i] = ' ';
            if (!isSubstring(key,letter))
            {
                printf("%c\n", key[i]);
            }
        }
    }
}

bool isSubstring(string text, char letter)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (letter == text[i])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return 0;
}