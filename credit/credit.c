#include <cs50.h>
#include <stdio.h>

int countDigits(long i);

int main(void)
{
    long num = get_long("Number: ");
    int count = countDigits(num);
    int numArray[count];
    printf("%i\n",count);
    for (int i = count; i > 0; i--)
    {
        numArray[i] = num%10;
        num /= 10;
        printf("%i",numArray[i]);
    }
    printf("\n");
}

int countDigits(long i)
{
    int ret=1;
    while (i/=10) ret++;
    return ret;
}