//Link: https://cses.fi/problemset/task/1638
#include <iostream>
#define N 1000
#define MOD int(1e9+7)
using namespace std;

int numberOfPaths[N + 1][N + 1];
bool grid[N + 1][N + 1];

int getNumberOfPaths(int size)
{
    int opt1, opt2;
    numberOfPaths[1][1] = 1;

    if(grid[1][1] == true || grid[0][0] == true)
    {
        return 0;
    }

    for (int row = 1; row <= size; row++)
    {
        for (int col = 1 ; col <= size; col++)
        {
            if(row == 1 && col == 1)continue;
            
            bool notTrap = !grid[row][col];
            
            opt1 = 0;
            opt2 = 0;
            
            if(notTrap)
            {
                opt1 = ((row-1) == 0)? 0: numberOfPaths[row-1][col];
                opt2 = ((col-1) == 0)? 0: numberOfPaths[row][col-1];
            }

            //printf("row = %d & col = %d \ntrap = %d; opt1 = %d; opt2 = %d\n\n",row, col, notTrap, opt1, opt2);
            numberOfPaths[row][col] = (opt1 + opt2)%MOD;
        }
    }

    return numberOfPaths[size][size];
    
}

int main()
{
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            char input;
            cin >> input;

            if (input == '*')
            {
                grid[row][col] = true;
            }
            else if (input == '.')
            {
                grid[row][col] = false;
            }
        }
    }


    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    printf("%d\n",getNumberOfPaths(n));
    return 0;
}