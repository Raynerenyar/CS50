#include <cs50.h>
#include <stdio.h>
#include <string.h>

// string organiseToArrays(string text, int wordCount);
int countWords(string text. int len);
int count_letters(string text, int len);
int countSentences(string text, int len)

int main(void)
{
    string text = get_string("Text: ");
    int len = strlen(text);
    int wordCount = countWords(text, len);
    int letterCount = letter_count(text, len);
    int senTenceCount = countSentences(text, len)
    // organiseToArrays(text, wordCount);
    double index = 0.0588 * 
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
        if (text[i] != 32)
        {
            letter_count++;
        }
    }
    return letter_count;
}