#include <iostream>
#include <vector>

using namespace std;

void search(int, int, vector<int> &);

int main()
{
    vector<int> set;
    set.push_back(1);
    set.push_back(2);
    set.push_back(3);

    vector<int> subset;
    search(1, set.size(), subset);
}

void search(int k, int n, vector<int> &subset)
{
    if (k == n + 1)
    {
        //process subsety
        if (subset[k] == subset.empty())
        {
            cout << "empty";
        }
        else
        {
            for (auto u : subset)
            {
                cout << u << " ";
            }
        }

        cout << endl;
    }
    else
    {
        //include k in the subset
        subset.push_back(k);
        search(k + 1, n, subset);
        subset.pop_back();
        //don't include k in the subset
        search(k + 1, n, subset);
    }
}