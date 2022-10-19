#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// string organiseToArrays(string text, int wordCount);
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
    // organiseToArrays(text, wordCount);
    printf("WordCount: %i, letterCount: %i, sentenceCount: %i\n", wordCount, letterCount, sentenceCount);
    double index = 0.0588 * (letterCount / wordCount * 100) - 0.296 * (sentenceCount / wordCount * 100) - 15.8;
    if (index > 16)
    {
        printf("Grade 16+");
    }
    else if (index < 1)
    {
        printf("Before Grade 1");
    }
    else printf("Grade %i", index);
    printf("%f\n", index);
}

// string organiseToArrays(string text, int wordCount)
// {
//     int len = strlen(text);
//     string words[wordCount];
//     int startIndex = 0;
//     for (int i = 0; i < len; i++)
//     {
//         // checks for ',', '!', '>'
//         if (text[i] == 33 || text[i] == 46 || text[i] == 63)
//         {
//             for (int j = startIndex; j < i; j++)
//             {
//                 text[j];
//             }
//         }
//         int word[];
//         word[i]  = text[i];
//     }
//     return "string";
// }

int countSentences(string text, int len)
{
    int sentenceCount = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}

int countWords(string text, int len)
{
    // int len = strlen(text);
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

int count_letters(string text, int len)
{
    // int len = strlen(text);
    int letter_count = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] != 32 && text[i] != 33 && text[i] != 46 && text[i] != 63)
        {
            letter_count++;
        }
    }
    return letter_count;
}