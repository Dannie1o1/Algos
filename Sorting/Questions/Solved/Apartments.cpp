#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// Link: https://cses.fi/problemset/task/1084
// Status: Accepted

int GetMaxAccommodationNumber(int numOfApplicants, int numOfApartments, int maxSizeDifference)
{
    int maxAccommodation = 0;
    int size = 0;
    vector<int> desiredAppartmentSizes;
    vector<int> availableAppartmentSizes;

    for (int i = 0; i < numOfApplicants; i++)
    {
        cin >> size;
        desiredAppartmentSizes.push_back(size);
    }

    for (int i = 0; i < numOfApartments; i++)
    {
        cin >> size;
        availableAppartmentSizes.push_back(size);
    }

    sort(desiredAppartmentSizes.begin(), desiredAppartmentSizes.end());
    sort(availableAppartmentSizes.begin(), availableAppartmentSizes.end());
    
    int i = 0;
    int j = 0;

    while (i < numOfApplicants and j < numOfApartments)
    {
        int desiredAppartmentSize = desiredAppartmentSizes[i];
        int availableAppartmentSize = availableAppartmentSizes[j];

        bool isWithinDesiredSizeRange = (abs(availableAppartmentSize - desiredAppartmentSize) <= maxSizeDifference);

        if (isWithinDesiredSizeRange)
        {
            maxAccommodation++;
            i++;
            j++;
        }
        else if (desiredAppartmentSize < availableAppartmentSize)
        {
            i++;
        }
        else
        {
            j++;
        }

    }

    return maxAccommodation;
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
    int numOfApplicants = 0; // 1 <= n <= 2e5
    int numOfApartments = 0; // 1 <= m <= 2e5 
    int maxSizeDifference = 0; // 0 <= k <= 1e9

    cin >> numOfApplicants >> numOfApartments >> maxSizeDifference;

    int maxAccommodation = GetMaxAccommodationNumber(numOfApplicants, numOfApartments, maxSizeDifference);

    cout << maxAccommodation;
}