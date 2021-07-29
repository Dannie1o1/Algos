#include <iostream>
#include <string>
#include <math.h>
#define N int(1e6)

int minReduction[N + 1];

using namespace std;

int getNumberLength(int number)
{
    int length = 0;
    int numberCopy = number;
    while (numberCopy > 0)
    {
        length++;
        numberCopy /= 10;
    }
    return length;
}

int getMinimalReductions(int number)
{
    //get the minimum amount of steps to reduce a number to zero
    //using the digits contain in the current number
    //Example: 27→20→18→10→9→0

    minReduction[0] = 0;
    for (int num = 1; num <= number; num++)
    {
        int numberLength = getNumberLength(num);
        //printf("numberLength : %d\n", numberLength);
        minReduction[num] = N+1;

        for (int digit = 0; digit < numberLength; digit++)
        {

            int currentDigitValue = (num / int(pow(double(10), double(digit)))) % 10;
            //printf("currentDigitValue : %d\n", currentDigitValue);
            if (currentDigitValue == 0)
            {
                continue;
            }
            else 
            {
                minReduction[num] = min(minReduction[num - currentDigitValue]+ 1, minReduction[num]);
            }
                

        }
        //printf("minReduction[%d] = %d\n\n", num, minReduction[num]);
    }

    // for (int i = 0; i <= number; i++)
    // {
    //     printf("minReduction[%d] = %d\n", i, minReduction[i]);
    // }

    return minReduction[number];
}

int main()
{
    int num;
    scanf("%d", &num);
    printf("%d\n", getMinimalReductions(num));
    return 0;
}