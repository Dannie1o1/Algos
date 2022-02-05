#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

typedef long long LL;

using namespace std;

// Link: https://cses.fi/problemset/task/1643
// Status: In-Progress

int main()
{
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    // File I/O
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // solution comes here
    vector<LL> array;

    LL size, num;
    cin >> size >> num;
    array.push_back(num);

    for (LL i = 1; i < size; i++)
    {
        cin >> num;
        num = max(num, array[i-1]+num);
        array.push_back(num);
    }

    sort(array.begin(), array.end());

    cout << *(array.end()-1);
    
}
