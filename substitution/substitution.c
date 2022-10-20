#define _GNU_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool isSubstring(string text);

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

            if (!isSubstring(key, len) && onlyAlpha)
            {
                key[i] = letter;
                printf("%c\n", key[i]);
            }
        }
    }
}

bool isSubstring(string text, int length)
{
    isSubstring(text, length -1)
    for (int i = 0; i < len; i++)
    {
        char letter = text[i];
        key[i] = ' ';
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