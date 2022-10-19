#include <cs50.h>
#include <stdio.h>

string organiseToArrays(string text);

int main(void)
{
    string text = get_string("Text: ");
    bool compare = text[0] == " ";
    printf("%i\n", compare);
}

// string organiseToArrays(string text)
// {
//     int len = strlen(text);
//     for (int i = 0; i < len; i++)
//     {
//         if (text[i] == )
//     }
// }