#include <iostream>
#include <queue>
#include <utility>

#define N 1000
#define INF INT_MAX

using namespace std;

int dist [N];
vector <bool> processed (N, false); 
vector <pair<int,int>> adj[N];
priority_queue < pair <int, int> > q;

//Dijkstra's Algo
// Time Complexity -> O (n+ m log(m))
void dijkstra(int x)// x = starting node
{
    for (int i = 1; i <= N; i++)
    {
        dist[i] = INF;
    }

    dist[0] = 0;

    q.push({0,x});

    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();

        if (processed[a]) 
        {
            continue;
        }
            
        processed[a] = true;

        for(auto u : adj[a])
        {
            int b = u.first;
            int w = u.second;

            if (dist[a]+w < dist[b])
            {
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
}

int main()
{
    return 0;
}