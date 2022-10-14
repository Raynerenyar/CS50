#include <cs50.h>
#include <stdio.h>

int countDigits(long i);

int main(void)
{
    long num = get_long("Number: ");
    int count = countDigits(num);
    int secondArrLen= (count/2);
    int firstArrLen = (count - (count/2));
    int secondArray[secondArrLen];
    int firstArray[firstArrLen];
    int i = count;
    int k = 0;
    int l = 0;
    int whichArray = 1;
    while (i > 0)
    {
        // last digit always goes into first array (2nd-to-last)
        if (whichArray ==  1)
        {
            firstArray[k] = num%10;
            num /= 10;
            whichArray = 2;
            // printf("%i   %i",i, firstArray[k]);
            k++;
        }
        else
        {
            secondArray[l] = num%10;
            num /= 10;
            whichArray = 1;
            // printf("%i   %i",i, secondArray[l]);
            l++;
        }
        i -= 1;
        // printf("\n");
    }
    int sum = 0;
    for (int a = 0; a < secondArrLen; a++)
    {
        int multiplyTwo = secondArray[a] * 2;
        // secondArray[a] *= 2;
        if (multiplyTwo >= 10)
        {
            sum += (1 + (multiplyTwo%10));
        }
        else sum += multiplyTwo;
        // printf("%i\n",sum);
    }
    int finalSum = sum;
    for (int b = 0; b < firstArrLen; b++)
    {
        if (firstArray[b] >= 10)
        {
            finalSum += (1 + (firstArray[b]%10));
        }
        else finalSum += firstArray[b];
    }
    // printf("%i",finalSum);
    // bool valid = true;
    if (finalSum%10 != 0)
    {
        printf("INVALID\n");
        // valid = false;
    }
    // checks if number is from AMEX, MASTER, or VISA
    if (count == 16 && secondArray[secondArrLen-1] == 5)
    {
        int digitCheck = firstArray[firstArrLen-1];
        if (digitCheck == 1 || digitCheck == 2 || digitCheck == 3 || digitCheck == 4 || digitCheck == 5)
        {
            printf("MASTERCARD\n");
        }
        else printf("INVALID\n");
    }
    else if (count == 15 && firstArray[firstArrLen-1] == 3)
    {
        int digitCheck = secondArray[secondArrLen-1];
        if (digitCheck == 7 || digitCheck == 4)
        {
            printf("AMEX\n");
        }
        else printf("INVALID\n");
    }
    else if (count == 16 && secondArray[secondArrLen-1] == 4) printf("VISA\n");
    else if (count == 13 && firstArray[firstArrLen-1] == 4) printf("VISA\n");
    else printf("INVALID\n");
    // check nums in first array
    // printf("first array\n");
    // for (int m = 0; m < secondArrLen; m++)
    // {
    //     printf("%i %i\n", m,secondArray[m]);
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
