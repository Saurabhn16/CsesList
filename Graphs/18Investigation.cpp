// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void ans(int v)
{
    if (v)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

signed main()
{
    fast;

    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dist(n + 1, INT_MAX);
        vector<int> cnt(n + 1, 0);
        vector<int> mn(n + 1, LLONG_MAX);
        vector<int> mx(n + 1, 0);

        for (int i = 0; i < m; i++)
        {
            int a, b, wt;
            cin >> a >> b >> wt;
            adj[a].push_back({b, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        cnt[1] = 1;
        mn[1] = 0;
        mx[1] = 0;
        dist[1] = 0;
        while (!pq.empty())
        {
            int wt = pq.top().first;
            int par = pq.top().second;
            pq.pop();
              if (wt > dist[par]) continue;
            for (auto it : adj[par])
            {
                int child = it.first;
                int cwt = it.second;

                if (dist[child] > dist[par] + cwt)
                {
                    cnt[child] = cnt[par];
                    mn[child] = 1 + mn[par];
                    mx[child] = 1 + mx[par];
                    dist[child] = dist[par] + cwt;
                    pq.push({dist[child], child});
                }
                else if (dist[child] == dist[par] + cwt)
                {
                    mn[child] = min(mn[child], 1 + mn[par]);
                    mx[child] = max(mx[child], 1 + mx[child]);
                    cnt[child] += cnt[par];
                }
            }
        }

        cout << dist[n] << " " << cnt[n] << " " << mn[n] << " " << mx[n] << endl;
    }
    return 0;
}