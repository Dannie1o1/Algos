#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

// Link: https://cses.fi/problemset/task/1640
// Status: Accepted

bool cmp (pair<int,int> &a, pair<int,int> &b)
{
    return (a.first < b.first);
}

pair<int,int> GetTwoIndicesThatFormSum(vector< pair<int,int> > &sortedArray, int targetSum)
{
    pair <int,int> solutionIndices = {-1,-1};

    auto itr = lower_bound(sortedArray.begin(), sortedArray.end(), make_pair(targetSum,0));

    while(itr != sortedArray.begin())
    {
        int diffFromTarget = targetSum - (*itr).first;
        auto itr2 = lower_bound(sortedArray.begin(),itr-1, make_pair(diffFromTarget,0));
        if (((*itr2).first + (*itr).first == targetSum) && diffFromTarget != 0)
        {
            solutionIndices = {(*itr2).second, (*itr).second};
            break;
        }
        else
        {
            itr--;
        }     
    }

    return solutionIndices;
}

int main()
{
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    // File I/O
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // solution comes here
    vector<pair<int,int> > array;

    int size, x;
    cin >> size >> x;

    for (int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        array.push_back(make_pair(num,i));
    }

    sort(array.begin(), array.end(), cmp);

    // for (auto a: array)
    // {
    //     cout << a.first << ":" << a.second << endl;
    // }

    auto pairOfTwoIndices = GetTwoIndicesThatFormSum(array, x);

    if (pairOfTwoIndices.first == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << pairOfTwoIndices.first + 1 << " " << pairOfTwoIndices.second + 1;
    }
    
}
