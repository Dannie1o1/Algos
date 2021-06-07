#include <vector>
#include <iostream>
#include <queue>

using namespace std;
#define N 1000

vector<int> adj[N];
bool visited[N];
int dist[N];
queue<int> q;

//Breath First Search; Time Complexity = O(n+m) 
//n - # of nodes ; m - # of edges
void bfs(int x)
{
    visited[x] = true;
    dist[x] = 0;
    q.push(x);

    while (!q.empty())
    {
       int s = q.front(); 
       q.pop();
       //process node s

       for (auto u: adj[s])
       {
           if (visited[u])
           {
               continue;
           }
           visited[u] = true;
           dist[u] = dist[s]+1;
           q.push(u);
       }
    }
}

int main()
{
    //cout << "hello world" << endl;
}