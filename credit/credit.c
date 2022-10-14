#include <cs50.h>
#include <stdio.h>

int countDigits(long i);

int main(void)
{
    long num = get_long("Number: ");
    int count = countDigits(num);
    int SecondArrLen= (count/2);
    int firstArrLen = (count - (count/2));
    int SecondArray[SecondArrLen];
    int firstArray[firstArrLen];
    int i = count;
    int whichArray = 2;
    int k = 0;
    int l = 0;
    while (i > 0)
    {
        if (whichArray ==  1)
        {
            SecondArray[k] = num%10;
            num /= 10;
            whichArray = 2;
            printf("%i   %i",i, SecondArray[k]);
            k++;
        }
        else
        {
            firstArray[l] = num%10;
            num /= 10;
            whichArray = 1;
            printf("%i   %i",i, firstArray[l]);
            l++;
        }
        i -= 1;
        printf("\n");
    }
    int sum = 0;
    for (int a = 0; a < SecondArrLen; a++)
    {
        SecondArray[a] *= 2;
        if (SecondArray[a] >= 10)
        {
            sum += (1 + (SecondArray[a]%10));
        }
        else sum += SecondArray[a];
        printf("%i\n",sum);
    }
    int finalSum = 0;
    for (int b = 0; b < firstArrLen; b++)
    {
        if (firstArray[b] >= 10)
        {
            finalSum += (1 + (firstArray[b]%10));
        }
        else finalSum += firstArray[b];
    }
    printf("%i\n",(sum+finalSum));

    // checks if number is from AE, Mast, or Visa

    // check nums in first array
    // printf("first array\n");
    // for (int m = 0; m < SecondArrLen; m++)
    // {
    //     printf("%i %i\n", m,SecondArray[m]);
    // }
    // printf("\n");
    // // check nums in second array
    // printf("second array\n");
    // for (int n = 0; n < firstArrLen; n++)
    // {
    //     printf("%i %i\n", n, firstArray[n]);
    // }
}

int countDigits(long i)
{
    int ret=1;
    while (i/=10) ret++;
    return ret;
}