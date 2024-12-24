#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        edges.emplace_back(a, b, x);
    }

    vector<int> dist(n + 1, -INF);
    dist[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto [a, b, x] : edges)
        {
            if (dist[a] != -INF && dist[a] + x > dist[b])
            {
                dist[b] = dist[a] + x;
            }
        }
    }

    vector<bool> inPositiveCycle(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        for (auto [a, b, x] : edges)
        {
            if (dist[a] != -INF && dist[a] + x > dist[b])
            {
                inPositiveCycle[b] = true;
            }
            if (inPositiveCycle[a])
            {
                inPositiveCycle[b] = true;
            }
        }
    }

    if (inPositiveCycle[n])
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << dist[n] << "\n";
    }

    return 0;
}
