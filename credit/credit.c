#include <cs50.h>
#include <stdio.h>

int countDigits(long i);

int main(void)
{
    long num = get_long("Number: ");
    int count = countDigits(num);
    int firstArray[(count%2)];
    int secondArray[(count-count%2)]
    printf("%i\n",count);
    int i = count;
    while (i--)
    {
        firstArray[i] = num%10;
        num /= 10;
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