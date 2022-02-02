#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

// Link: https://cses.fi/problemset/task/1629
// Status: Accepted
bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return (a.second < b.second);
}


int GetMaxAmountOfMoviesCanWatch(vector<pair<int, int>> movieSchedule)
{
    int maxAmountOfMoviesOneCanWatch = 0;
    int currentEndTime = -1;
    int temp = 0;

    for (auto movie : movieSchedule)
    {
        int startTime = movie.first;

        if (currentEndTime <= startTime)
        {
            maxAmountOfMoviesOneCanWatch = max(maxAmountOfMoviesOneCanWatch, ++temp);
            currentEndTime = movie.second;
        }

    }

    return maxAmountOfMoviesOneCanWatch;
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
    vector<pair<int, int>> movieSchedule;

    int numberOfMovies;
    cin >> numberOfMovies;

    for (int i = 0; i < numberOfMovies; i++)
    {
        int startTime, endTime;
        cin >> startTime >> endTime;
        movieSchedule.push_back(make_pair(startTime, endTime));
    }

    sort(movieSchedule.begin(), movieSchedule.end(), cmp);

    // for (auto movie: movieSchedule)
    // {
    //     cout << movie.first << ":" << movie.second << endl;
    // }

    int maxNumberOfWatchableMovies = GetMaxAmountOfMoviesCanWatch(movieSchedule);

    cout << maxNumberOfWatchableMovies;
}
