#include <cs50.h>
#include <stdio.h>
#include <string.h>

string organiseToArrays(string text);

int main(void)
{
    string text = get_string("Text: ");
    organiseToArrays(text);
}

string organiseToArrays(string text)
{
    int len = strlen(text);
    int startIndex = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] == 32)
        {
            for (int j = startIndex; j < i; j++)
            {
                text[j]
            }
        }
        int word[];
        word[i]  = text[i];
    }
}