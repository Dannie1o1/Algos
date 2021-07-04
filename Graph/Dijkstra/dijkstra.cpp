#include <iostream>
#include <queue>
#include <utility>

#define N 5
#define INF 1000000000

using namespace std;

int dist[N+1];
vector<bool> processed(N+1, false);
vector<pair<int, int>> adj[N+1];
priority_queue<pair<int, int>> q;

void createGraph()
{
    int a, b, w;

    //cout << "Enter Graph Edges\n";
    while (cin >> a >> b >> w)
    {
        cout << "a = " << a << " b = " << b << " w = " << w << "\n";
        adj[a].push_back({b, w});
    }
}

//Dijkstra's Algo
// Time Complexity -> O (n+ m log(m))
void dijkstra(int x) // x = starting node
{
    for (int i = 1; i <= N; i++)
    {
        dist[i] = INF;
    }

    dist[x] = 0;

    q.push({0, x});

    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();

        if (processed[a])
        {
            continue;
        }

        processed[a] = true;

        for (auto u : adj[a])
        {
            int b = u.first;
            int w = u.second;

            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
}

int main()
{
    //Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    //File I/O
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    createGraph();
    dijkstra(5);

    // for (auto u : adj)
    // {
    //     //cout << u << "\n";

    //     for (auto v : u)
    //     {
    //         cout << v.first << "," << v.second << " ";
    //     }
    //     cout << "\n";
    // }

    for (auto u : dist)
    {
        cout << u << "\n";
    }

    return 0;
}