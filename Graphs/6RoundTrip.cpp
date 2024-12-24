#include <bits/stdc++.h>
using namespace std;

void findCycle(int start, int end, vector<int> &parent, vector<int> &cycle)
{
    cycle.push_back(start);
    while (start != end)
    {
        start = parent[start];
        cycle.push_back(start);
    }
    cycle.push_back(cycle[0]);
    reverse(cycle.begin(), cycle.end());
}

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &parentTracker, vector<int> &cycle)
{
    visited[node] = true;
    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            parentTracker[neighbor] = node;
            if (dfs(neighbor, node, adj, visited, parentTracker, cycle))
            {
                return true;
            }
        }
        else if (neighbor != parent)
        {

            findCycle(node, neighbor, parentTracker, cycle);
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> parentTracker(n + 1, -1);
    vector<int> cycle;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && dfs(i, -1, adj, visited, parentTracker, cycle))
        {
            cout << cycle.size() << "\n";
            for (int city : cycle)
            {
                cout << city << " ";
            }
            cout << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
