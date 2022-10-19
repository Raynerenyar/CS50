#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int countWords(string text, int len);
int count_letters(string text, int len);
int countSentences(string text, int len);

int main(void)
{
    string text = get_string("Text: ");
    int len = strlen(text);
    int wordCount = countWords(text, len);
    int letterCount = count_letters(text, len);
    int sentenceCount = countSentences(text, len);
    float L = ((float) letterCount / wordCount * 100);
    float S = ((float) sentenceCount / wordCount * 100);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int countSentences(string text, int len)
{
    int sentenceCount = 0;
    for (int i = 0; i < len; i++)
    {
        char character = text[i];
        if (character == '!' || character == '.' || character == '?')
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}

int countWords(string text, int len)
{
    int wordCount = 0;
    for (int i = 0; i < len; i++)
    {
        char character = text[i];
        if (character == ' ')
        {
            wordCount++;
        }
    }
    return wordCount + 1;
}

int count_letters(string text, int len)
{
    int letter_count = 0;
    for (int i = 0; i < len; i++)
    {
        char character = text[i];
        if (isalpha(character))
        {
            letter_count++;
        }
    }
    return letter_count;
}