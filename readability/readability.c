#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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
    printf("WordCount: %i, letterCount: %i, sentenceCount: %i\n", wordCount, letterCount, sentenceCount);
    float L = ((float) letterCount / wordCount * 100);
    float S = ((float) sentenceCount / wordCount * 100);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    printf("%f\n", index);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else printf("Grade %i\n", (int) index);
}

int countSentences(string text, int len)
{
    int sentenceCount = 0;
    for (int i = 0; i < len; i++)
    {
        char character = text[i];
        if (character == 33 || character == 46 || character == 63)
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
        // char character = text[i];
        if ((char) text[i] == ' ')
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
        if (character != ' ' && character != '!' && character != '.' && character != '?' && character != ',')
        {
            letter_count++;
        }
    }
    return letter_count;
}