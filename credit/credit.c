#include <cs50.h>
#include <stdio.h>

int countDigits(long i);

int main(void)
{
    long num = get_long("Number: ");
    int count = countDigits(num);
    int numArray[count];
    for (int i = 0; i < count; i++)
    {
        
    }

}

int countDigits(long i)
{
    int ret=1;
    while (i/=10) ret++;
    return ret;
}