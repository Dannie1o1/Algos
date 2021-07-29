//Link: https://cses.fi/problemset/task/1633
//Status: ACCEPTED

#include <iostream>
#define MOD (1e9 + 7)
#define N (1e6) //1 <= n <= 10^6

using namespace std;
int combs[int(N+1)];

int getInput()
{
    int n = 0;
    scanf("%i", &n);
    return n;
}

int getNumOfDiceCombs(int n)
{
    combs[0] = 0;
    combs[1] = 1;
    

    if (combs[n] > 0)
    {
        return combs[n];
    }
    else
    {
        for (int x = 2; x <= n; x++)
        {
            for (int diceVals = 1; diceVals<=6; diceVals++){
                if(x-diceVals > 0){
                    combs[x] += combs[x-diceVals];
                    combs[x] %= int(MOD);
                }
                else if(x-diceVals == 0){
                    combs[x] += combs[x-diceVals]+1;
                    combs[x] %= int(MOD);
                }
            }
        }
    }

    return combs[n] % int(MOD);
}

int main()
{
    // printf("Hello world!\n");
    // printf("MOD = %f\n", MOD);
    // printf("N = %f\n", N);

    int n = getInput();
    //printf("n = %i\n", n);
    printf("%i\n", getNumOfDiceCombs(n));

    return 0;
}