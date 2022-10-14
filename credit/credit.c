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
            // printf("%li   %i",num, firstArray[i]);
            // printf("%i",firstArray[i]);
            // printf("\n");
            printf(" %li\n",num);
        }
        else
        {
            secondArray[i] = num%10;
            num /= 10;
            whichArray = 1;
            // printf("%li   %i",num, secondArray[i]);
            // printf("%i",secondArray[i]);
            // printf("\n");
            printf(" %li\n",num);
        }
        i -= 1;
        // printf(" %i",i);
    }
    // printf("%i\n", firstArray[8]);
    // check nums in first array
    // for (int j = 0; j < count; j++)
    // {
    //     printf("%i",firstArray[j]);
    // }
    // printf("\n");
    // check nums in second array
    printf("%d ",secondArray[0]);
    printf("%d ",secondArray[1]);
    printf("%d ",secondArray[2]);
    printf("%d ",secondArray[3]);
    printf("%d ",secondArray[4]);
    printf("%d ",secondArray[5]);
    printf("%d ",secondArray[6]);
    printf("%d ",secondArray[7]);
    printf("%d ",secondArray[8]);
    printf("%d ",secondArray[9]);
    printf("%d ",secondArray[10]);
    printf("%d ",secondArray[11]);
    // for (int k = 0; k < count; k++)
    // {
    //     printf("%d ",secondArray[k]);
    // }
}

int countDigits(long i)
{
    int ret=1;
    while (i/=10) ret++;
    return ret;
}