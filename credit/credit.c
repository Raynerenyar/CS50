#include <cs50.h>
#include <stdio.h>

int countDigits(long i);

int main(void)
{
    long num = get_long("Number: ");
    int count = countDigits(num);
    int firstArray[(count%2)];
    int secondArray[(count-count%2)];
    int i = count;
    string whichArray = "first";
    while (i--)
    {
        if (whichArray ==  "first")
        {
            firstArray[i] = num%10;
            num /= 10;
            whichArray = "second"
        }
        if (whichArray == "second")
        {
            firstArray[i] = num%10;
            num /= 10;
            whichArray = "first"
        }
        printf("%i",firstArray[i]);
    }
    printf("\n");
}

int countDigits(long i)
{
    int ret=1;
    while (i/=10) ret++;
    return ret;
}