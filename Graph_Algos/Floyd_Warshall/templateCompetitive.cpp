#include <iostream>
#include <vector>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

vvi createAdjMatrix(int v)
{
    vvi adj(v + 1, vi(v + 1, 0));
    int a, b, w;
    while (cin >> a >> b >> w)
    {
        adj[a][b] = w;
    }
    return adj;
}

vvi createDistMatrix(vvi &adj)
{
    vvi dist(adj.size(), vi(adj.size(), 0));

    for (int i = 1; i <= adj.size()-1; i++)
    {
        for (int j = 1; j <= adj[i].size()-1; j++)
        {
            if (i == j)
                dist[i][j] = 0;

            else if (adj[i][j])
                dist[i][j] = adj[i][j];

            else
                dist[i][j] = INF;
        }
    }

    return dist;
}

void floydWarshall (vvi &dist, int n)
{
    for (int k = 1; k<=n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j<=n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
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

    // solution comes here
    int v; //vertices
    cin >> v;
    cout << "Number vertices..." << v << "\n";
    vvi adj = createAdjMatrix(v);
    vvi dist = createDistMatrix(adj);
    floydWarshall(dist, v);

    REP(i, 1, v)
    {
        //cout << "index " << i << " : ";
        REP(j, 1, v)
        {
            cout << dist[i][j] << " ";
            
        }
        cout << "\n";
    }
}