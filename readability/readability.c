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
    int word[];
    for (int i = 0; i < len; i++)
    {
        word[i]  = text[i];
    }
}