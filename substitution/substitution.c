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
    bool isCorrectLength = (len == 3); // demo with 3 first
    bool repeatChar = isSubstring(key);
    bool isAlpha = checkAlpha(key);
    // check num of args and length
    if (argc > 2)
    {
        printf("./substitution key\n");
        return 1;
    }
    else if (!isCorrectLength)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (!isAlpha)
    {
        printf("Key must only contain alphabetic characters\n");
        return 1;
    }
    else if (!repeatChar)
    {
        printf("Key must not contain repeated characters\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            int onlyAlpha = isalpha(key[i]); // returns>0 if all alphabets

            if (!repeatChar && onlyAlpha)
            {
                printf("%c\n", key[i]);
            }
        }
    }
}

// return true if there's repeat char
bool isSubstring(string text)
{
    int len = strlen(text);
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i+1; j<len; j++)
        {
            if (text[i] == text[j])
            {
                return true;
            }
        }
    }
    return false;
}

// return true text is all alpha
bool checkAlpha(string text)
{
    int len = strlen(text);
    for (int i = 0; i<len; i++)
    {
        if (!isalpha(text[i]))
        {
            return false;
        }
    }
    return true;
}