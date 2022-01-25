#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// Link: https://cses.fi/problemset/task/1091
// Status: Time-Limit-Exceeded

// Returns the cost of an available ticket than can be purchased
// Given a budget
// tickets array must be sorted before inputting into this function
int GetAvailbleTicket(vector<int> &ticketPrices, vector<bool> &isTicketAvailble, int budget)
{
    int availableTicketPrice = -1; // -1 represent unavailable of ticket given the current budget
    // Get the closest available ticket cost from the tickets array
    auto ticketIterator = upper_bound(ticketPrices.begin(), ticketPrices.end(), budget);

    if (ticketIterator == ticketPrices.end())
    {
        ticketIterator--;
    }

    // Search for next available ticket that is less than the budget (i.e ticketCost < budget)
    while (ticketIterator >= ticketPrices.begin())
    {
        int index = (ticketIterator - ticketPrices.begin()); 
        int ticketPrice = ticketPrices[index];

        if (isTicketAvailble[index] && budget >= ticketPrice)
        {
            availableTicketPrice = ticketPrice;
            isTicketAvailble[index] = false;
            break;
        }
        else // Ticket no available
        {
            ticketIterator--;
        }
    }

    return availableTicketPrice;
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
    int n, m;

    cin >> n >> m;

    vector<int> customerBudgets;
    vector<int> ticketPrices;
    vector<bool> isTicketAvailable(m, true);

    for (int i = 0; i < n; i++)
    {
        int ticketPrice = 0;
        cin >> ticketPrice;
        ticketPrices.push_back(ticketPrice);
    }

    for (int i = 0; i < m; i++)
    {
        int budget = 0;
        cin >> budget;
        customerBudgets.push_back(budget);
    }

    sort(ticketPrices.begin(), ticketPrices.end());

    for (int i = 0; i < m; i++)
    {
        cout << GetAvailbleTicket(ticketPrices, isTicketAvailable, customerBudgets[i]) << "\n";
    }
}