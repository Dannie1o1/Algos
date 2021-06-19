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
        //process subset
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

// k = 1; n = 3;
//search(1)
    //k = 1 
    //subset = 1
    //search(2)
        // k = 2
        // subset = 1, 2
        // search (3)
            // k = 3
            // subset = 1, 2, 3
            // search (4)
                //k = 4
                // k == n+1 
                //print subset (1,2,3)
                //end of this call
            //subset = 1,2
            //search (4)
                // k = 4
                // k == n+1 
                //print subset (1,2)
                //end of this call
            //end of this call
        // subset = 1
        // search (3)
            // k = 3
            // subset = 1,3
            // search(4)
                //k = 4
                // k == n+1 
                //print subset (1,3)
                //end of this call
            //subset = 1
            // search(4)
                // k = 4
                // k == n+1 
                //print subset (1)
                //end of this call
        //end of this call
    //subset = empty
    //search(2)
        // k = 2
        // subset = 2
        // search(3)
            // k = 3
            // subset = 2, 3
            // search (4)
                // k = 4
                // k == n+1
                // print subset(2,3)
                //end of this call
            // subset = 2
            // search(4)
                // k = 4
                // k == n+1
                // print subset(2)
                // end of this call
            // end of this call
        // subset = empty
        // search(3)
            // k = 3
            // subset = 3
            // search(4)
                // print subset (3)
                // end of this call
            // subset = empty
            // search(4)
                // print subset (empty)
                // end of this call
            // end of this call
        // end of this call
    //end of this call



