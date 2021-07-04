#include <vector>
#include <iostream>

using namespace std;
#define N 1000

vector <int> adj[N];
bool visited[N];

//Depth First Search; Time Complexity = O(n+m) 
//n - # of nodes ; m - # of edges
void dfs(int s)
{
    if (visited[s])
    {
        return;
    }

    visited[s] = true;    

    //process node s
    for (auto u: adj[s])
    {
        dfs(u);
    }
}

int main()
{
    //cout << "hello world" << endl;
}