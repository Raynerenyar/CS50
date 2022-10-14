#include <cs50.h>
#include <stdio.h>

int count(long i);

int main(void)
{
    long num = get_long("Number: ");
    printf("%i\n",count(num));

}

int count(long i)
{
    int ret=1;
    while (i/=10) ret++;
    return ret;
}