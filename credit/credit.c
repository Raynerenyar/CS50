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
    int whichArray = 1;
    while (i--)
    {
        if (whichArray ==  1)
        {
            firstArray[i] = num%10;
            num /= 10;
            whichArray = 2;
        }
        if (whichArray == 2)
        {
            firstArray[i] = num%10;
            num /= 10;
            whichArray = 1;
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