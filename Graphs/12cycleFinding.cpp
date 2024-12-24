#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, long long>> edges;
    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    int x = -1;
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        x = -1;
        for (auto [u, v, w] : edges)
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1)
    {

        cout << "NO\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            x = parent[x];
        }

        vector<int> cycle;
        for (int v = x;; v = parent[v])
        {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle)
        {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
