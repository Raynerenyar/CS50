#include <cs50.h>
#include <stdio.h>
#include <string.h>

string organiseToArrays(string text, int wordCount);
int countWords(string text);

int main(void)
{
    string text = get_string("Text: ");
    int wordCount = countWords(text);
    organiseToArrays(text, wordCount);
}

string organiseToArrays(string text, int wordCount)
{
    int len = strlen(text);
    string words[wordCount];
    int startIndex = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] == 32)
        {
            for (int j = startIndex; j < i; j++)
            {
                text[j];
            }
        }
        int word[];
        word[i]  = text[i];
    }
    return "string";
}

int countWords(string text)
{
    int len = strlen(text);
    int wordCount = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] == 32)
        {
            wordCount++;
        }
    }
    return wordCount + 1;
}