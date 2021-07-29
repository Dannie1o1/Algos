//link: https://cses.fi/problemset/task/1634
#include <iostream>
#include <vector>
#define C int(1e6)
#define N 100
#define X int(1e6)
#define INF 2000000000
#define MOD int(1e9 + 7)


using namespace std;


//Constraints
// 1 <= n <= 100
// 1 <= x <= 10^6
// 1<= ci <= 10^6
int sum[X+1];
vector<int> coins;

int getSum(int n)
{
    sum[0] = 1;

    if(sum[n]!=0)
    {
        return sum[n];
    }
    else
    {
        for (int x = 1; x <= n; x++)
        {
            for (auto c : coins)
            {
                if (x - c >= 0)
                {
                    sum[x] += sum[x - c];
                    sum[x] %= MOD;
                }
            }
        }
    }


    return sum[n];
}

int main(){

    for(int i=0; i<X+1; i++)
    {
        sum[0] = 0;
    }

    int n,x;
    scanf("%d%d", &n,&x);

    for(int i = 0; i < n; i++){
        int num;
        scanf("%d",&num);
        coins.push_back(num);
    }

    printf("%d\n", getSum(x));

    return 0;
}