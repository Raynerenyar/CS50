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
    bool repeatChar = isSubstring(key);
    // check num of args and length
    if (argc > 2)
    {
        printf("./substitution key");
        return 1;
    }
    else if (correctLength)
    {
        printf("Key must contain 26 characters");
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