#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int color, vector<int> &colors, vector<vector<int>> &adj) {
    colors[node] = color;  for (auto neighbor : adj[node]) {
        if (colors[neighbor] == -1) {
           if (!dfs(neighbor, color ^ 1, colors, adj)) {
                return false;   }
        } else if (colors[neighbor] == color) {
            return false;   }
    }
    return true; }

bool isBipartiteDFS(int n, vector<vector<int>> &adj) {
    vector<int> colors(n + 1, -1);   for (int i = 1; i <= n; i++) {
        if (colors[i] == -1) {
            if (!dfs(i, 0, colors, adj)) {
                return false;      }
        }
    }
    for(int i=1;i<=n;i++){
      cout<<colors[i]+1<<" ";
    }
    cout<<endl;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (isBipartiteDFS(n, adj)) {
       
    } else {
       cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
