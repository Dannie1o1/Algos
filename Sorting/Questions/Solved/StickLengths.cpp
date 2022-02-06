#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
typedef long long LL;
using namespace std;

// Link: https://cses.fi/problemset/task/1074
// Status: Accepted

int main()
{
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    // // File I/O
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // solution comes here
    vector<LL> array;

    LL size, num;
    cin >> size;

    for (LL i = 0; i < size; i++)
    {
        cin >> num;
        array.push_back(num);
    }

    sort(array.begin(), array.end());

    LL stickLengthToRuleThemAll = array[(array.size()) / 2];
    LL minCost = 0;
    if (stickLengthToRuleThemAll > 0)
    {
        for (LL i = 0; i < array.size(); i++)
        {
            minCost += abs(array[i] - stickLengthToRuleThemAll);
        }
    }

    cout << minCost;
}
