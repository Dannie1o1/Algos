#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// link: https://cses.fi/problemset/task/1090
// status: Accepted

int GetMinNumOfRequiredGondolas(int numOfChildren, int maxGondolaWeight)
{
    int minNumOfGondolas = 0;

    vector<int> childrenWeights;

    for (int i = 0; i < numOfChildren; i++)
    {
        int weight = 0;
        cin >> weight;
        childrenWeights.push_back(weight);
    }

    sort(childrenWeights.begin(), childrenWeights.end());

    auto endPointer = childrenWeights.end() - 1;
    auto startPointer = childrenWeights.begin();

    while (startPointer <= endPointer)
    {
        int child1 = *startPointer;
        int child2 = *endPointer;

        bool canFitTwoChildrenInGondola = (child1 + child2) <= maxGondolaWeight;

        if (canFitTwoChildrenInGondola)
        {
            startPointer++;
            minNumOfGondolas++;
        }
        else if (child2 <= maxGondolaWeight) // Only one child can fit
        {
            minNumOfGondolas++;
        }

        endPointer--;
    }

    return minNumOfGondolas;
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
    int numOfChildren = 0;
    int maxGondolaWeight = 0;

    cin >> numOfChildren >> maxGondolaWeight;

    int minNumOfRequiredGondolas = GetMinNumOfRequiredGondolas(numOfChildren, maxGondolaWeight);

    cout << minNumOfRequiredGondolas;
}