#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num = get_long("Number: ");

    unsigned int count(unsigned int i) {
    unsigned int ret=1;
    while (i/=10) ret++;
    return ret;
}
}