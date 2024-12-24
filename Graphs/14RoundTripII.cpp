#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005]; // adjacency list for the graph
vector<int> parent(100005, -1); // stores parent of each node during DFS
vector<int> visited(100005, 0); // 0: not visited, 1: visiting, 2: visited
vector<int> cycle; // stores the cycle path

bool dfs(int node) {
    visited[node] = 1; // mark the node as visiting
    for (int next : adj[node]) {
        if (visited[next] == 1) { // found a cycle
            // Reconstruct the cycle
            cycle.push_back(next);
            int cur = node;
            while (cur != next) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(next);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
        if (visited[next] == 0) {
            parent[next] = node;
            if (dfs(next)) return true;
        }
    }
    visited[node] = 2; // mark the node as completely visited
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Read the edges (flights)
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // Try to find a cycle starting from each unvisited node
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            if (dfs(i)) {
                cout << cycle.size() << "\n";
                for (int city : cycle) {
                    cout << city << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }

    // If no cycle is found
    cout << "IMPOSSIBLE\n";
    return 0;
}
