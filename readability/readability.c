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
    printf("L is %f\n", L);
    printf("S is %f\n", S);
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

// #include <stdio.h>
// #include <cs50.h>
// #include <stdbool.h>
// #include <math.h>


// int main(void)
// {
//     int coleman_Liau_index_formula(string text);
//     void print_grade(int grade);

//     int grade;
//     string text;

//     text = get_string("Text: ");
//     grade = coleman_Liau_index_formula(text);
//     print_grade(grade);
// }


// int coleman_Liau_index_formula(string text)
// {
//     int formula(int letters, int words, int sentences);
//     bool is_alpha_num(char c);
//     bool is_space(char c);
//     bool is_end(char c);

//     int i = 0, letters = 0, words = 0, sentences = 0;
//     bool is_word;

//     while (text[i]) {
//         char character = text[i];

//         if (is_alpha_num(character)) {
//             letters++;
//             is_word = true;
//         } else if (character == '-' && is_word) {
//             is_word = true;
//         } else if ((is_space(character) || (character == ',')) && is_word) {
//             words++;
//             is_word = false;
//         } else if (is_end(character) && is_word) {
//             words++;
//             is_word = false;
//             sentences++;
//         }

//         i++;
//     }

//     return formula(letters, words, sentences);
// }


// void print_grade(int grade)
// {
//     if (grade < 1)
//         printf("Before Grade 1\n");
//     else if (grade >= 16)
//         printf("Grade 16+\n");
//     else
//         printf("Grade %i\n", grade);
// }

// bool is_alpha_num(char c)
// {
//     return ((c >= 'a') && (c <= 'z')) ? true :
//            ((c >= 'A') && (c <= 'Z')) ? true :
//            ((c >= '0') && (c <= '9')) ? true : false;
// }

// bool is_space(char c)
// {
//     return c == ' ' ? true : false;
// }

// bool is_end(char c)
// {
//     return c == '.' ? true :
//            c == '!' ? true :
//            c == '?' ? true : false;
// }


// int formula(int letters, int words, int sentences)
// {
//     float L, S;

//     // Average number of letters per 100 words.
//     L = (float) letters / words * 100;

//     // Average number of sentences per 100 words .
//     S = (float) sentences / words * 100;

//     return (int) round(0.0588 * L - 0.296 * S - 15.8);
// }