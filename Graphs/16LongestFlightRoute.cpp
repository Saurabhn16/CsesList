// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);



vector<int> topologicalSort(int n, const vector<vector<int>>& adj) {
    vector<int> in_degree(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            ++in_degree[v];
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (int v : adj[u]) {
            --in_degree[v];
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topo_order;
}

pair<int, vector<int>> findLongestPath(int n, int m, const vector<pair<int, int>>& flights) {
    vector<vector<int>> adj(n + 1);
    for (const auto& flight : flights) {
        adj[flight.first].push_back(flight.second);
    }

  vector<int> topo_order = topologicalSort(n, adj);

    vector<int> dist(n + 1, INT_MIN);
    vector<int> parent(n + 1, -1);

    dist[1] = 1;  
    for (int u : topo_order) {
        if (dist[u] == INT_MIN) continue;  for (int v : adj[u]) {
            if (dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }

   if (dist[n] == INT_MIN) {
        return {-1, {}};
    }

 
    vector<int> path;
    for (int current = n; current != -1; current = parent[current]) {
        path.push_back(current);
    }
    reverse(path.begin(), path.end());

    return {dist[n], path};
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> flights(m);
    for (int i = 0; i < m; ++i) {
        cin >> flights[i].first >> flights[i].second;
    }

   auto result = findLongestPath(n, m, flights);

    if (result.first == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << result.first << "\n";
        for (int city : result.second) {
            cout << city << " ";
        }
        cout << "\n";
    }

    return 0;
}
