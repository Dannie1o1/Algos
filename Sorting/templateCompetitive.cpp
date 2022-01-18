#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void setSol()
{
    set<int> s;
    int i, num;

    cin >> i;

    for (int x = 1; x <= i; x++)
    {
        cin >> num;
        s.insert(num);
    }

    cout << s.size();
}

/* Returns the cnt of unique numbers given a list of integers */
int sortSol()
{
    vector<int> v;
    
    int x = 0;
    int num = 0;

    cin >> x;

    for (int i = 0; i < x; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());

    int cnt = 1;

    for(int i = 1; i<v.size();i++)
    {
        if (v[i-1] != v[i]){
            cnt++;
        }
    }

    return cnt;
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
    // setSol();
    cout << sortSol();
    
}