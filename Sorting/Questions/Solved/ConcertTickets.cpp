#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

// Link: https://cses.fi/problemset/task/1091
// Status: Accepted

// Returns the cost of an available ticket than can be purchased
// Given a budget
// tickets array must be sorted before inputting into this function
int GetAvailbleTicket(set< pair <int,int> > &ticketPrices, int budget)
{
    int availableTicketPrice = -1; // -1 represent unavailable of ticket given the current budget
    // Get the closest available ticket cost from the tickets array
    auto ticketIterator = ticketPrices.lower_bound({budget+1,0});

    // Search for next available ticket that is less than the budget (i.e ticketCost < budget)
    if (ticketIterator != ticketPrices.begin())
    {
        ticketIterator--;
        int ticketPrice = (*ticketIterator).first;
        int index = (*ticketIterator).second;

        if (budget >= ticketPrice)
        {
            availableTicketPrice = ticketPrice;
            ticketPrices.erase(ticketIterator);
        }
    }

    return availableTicketPrice;
}

int main()
{
    //Fast I/O
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    // //File I/O
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // solution comes here
    int n, m;

    cin >> n >> m;

    vector<int> customerBudgets;
    set< pair <int, int> > ticketPrices;

    for (int i = 0; i < n; i++)
    {
        int ticketPrice = 0;
        cin >> ticketPrice;
        ticketPrices.insert({ticketPrice,i});
    }

    for (int i = 0; i < m; i++)
    {
        int budget = 0;
        cin >> budget;
        customerBudgets.push_back(budget);
    }

    for (int i = 0; i < m; i++)
    {
        cout << GetAvailbleTicket(ticketPrices, customerBudgets[i]) << "\n";
    }
}