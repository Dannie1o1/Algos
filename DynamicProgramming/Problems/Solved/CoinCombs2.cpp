//link: https://cses.fi/problemset/task/1634
#include <iostream>
#include <vector>
#include <utility>

#define C int(1e6)
#define N 100
#define X int(1e6)
#define INF 2000000000
#define MOD int(1e9 + 7)

/*
    Scratch Pad:

    Coins: {2,3,5}

    value |cnt|solutions
    0 |0  | -
    1 |0  | -
    2 |1  | 2
    3 |1  | 3
    4 |1  | 2+2
    5 |2  | 2+3; 5 (3+2)
    6 |2  | 2+2+2; 3+3
    7 |2  | 2+2+3; 2+5
    8 |3  | 2+2+2+2; 2+3+3; 3+5
    9 |3  | 2+2+2+3; 3+3+3; 2+2+5
    10|3  | 2+2+2+2+2; 2+2+3+3; 2+3+5; 5+5 

    Solution: https://youtu.be/-pXjopzMVrE
*/

using namespace std;

//Constraints
// 1 <= n <= 100
// 1 <= value <= 10^6
// 1<= ci <= 10^6
int sum[X + 1];
vector<int> coins;

int getSum(int desiredSum)
{
    sum[0] = 1;

    for (int coinNum = 1; coinNum <= coins.size(); coinNum++)
    {
        for (int value = 0; value <= desiredSum; value++)
        {
            if(value-coins[coinNum-1] >= 0)
            {
                sum[value] += sum[value-coins[coinNum-1]];
                sum[value] %= MOD;
            }
        }
        cout << endl;
    }
    return sum[desiredSum];
}

int main()
{
    int n, x;

    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        coins.push_back(num);
    }

    printf("%d\n", getSum(x));

    return 0;
}