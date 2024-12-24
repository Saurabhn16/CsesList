#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int INF = 1e18;

signed main()
{
    fast;
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    dist[1][0] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 1, 0});

    while (!pq.empty())
    {
        auto [wt, u, bol] = pq.top();
        pq.pop();

        if (wt > dist[u][bol])
            continue;

        for (auto [v, cost] : adj[u])
        {
            if (dist[v][bol] > wt + cost)
            {
                dist[v][bol] = wt + cost;
                pq.push({dist[v][bol], v, bol});
            }

            if (!bol && dist[v][1] > wt + cost / 2)
            {
                dist[v][1] = wt + cost / 2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << endl;

    return 0;
}
