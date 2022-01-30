#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

// Link: https://cses.fi/problemset/task/1619
// Status: Accepted

int GetMaxAmountOfCustomers(set< pair< int, bool> > &sortListOfCustomerArrivalsAndDepartures)
{
    int maxAmountOfCustomers = 0;
    int temp = 0;

    for (auto customer : sortListOfCustomerArrivalsAndDepartures)
    {
        int time = customer.first;
        bool isCustomerCurrentlyThere = customer.second;

        if (isCustomerCurrentlyThere)
        {
            maxAmountOfCustomers = max(maxAmountOfCustomers, ++temp);
        }
        else
        {
            temp--;
        }
    }
    

    return maxAmountOfCustomers;
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
    int numOfCustomers;
    set < pair <int, bool> > customerArrivalAndDepartureTimes;

    cin >> numOfCustomers;

    for (int i = 0; i < numOfCustomers; i++)
    {
        int arrival, departure;
        cin >> arrival >> departure;
        customerArrivalAndDepartureTimes.insert({arrival, true});
        customerArrivalAndDepartureTimes.insert({departure, false});
    }
    
    int maxAmountOfCustomers= GetMaxAmountOfCustomers(customerArrivalAndDepartureTimes);

    cout << maxAmountOfCustomers;
}
