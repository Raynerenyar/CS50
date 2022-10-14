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
    int whichArray = 2;
    printf("%i\n",i);
    while (i>0)
    {
        if (whichArray ==  1)
        {
            firstArray[i] = num%10;
            num /= 10;
            whichArray = 2;
            printf("%li   %i",num, firstArray[i]);
            // printf("%i",firstArray[i]);
            printf("\n");
        }
        if (whichArray == 2)
        {
            secondArray[i] = num%10;
            num /= 10;
            whichArray = 1;
            printf("%li   %i",num, secondArray[i]);
            // printf("%i",secondArray[i]);
            printf("\n");
        }
        i -= 1;
        printf("    %i\n",i);
    }
    printf("\n");
    // check nums in first array
    // for (int j = 0; j < count; j++)
    // {
    //     printf("%i",firstArray[j]);
    // }
    // printf("\n");
    // // check nums in second array
    // for (int k = 0; k < count; k++)
    // {
    //     printf("%i",secondArray[k]);
    // }
}

int countDigits(long i)
{
    int ret=1;
    while (i/=10) ret++;
    return ret;
}