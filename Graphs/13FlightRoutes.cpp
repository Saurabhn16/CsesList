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
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
        }

        int INF = 1e18;
        vector<vector<int>> dist(n + 1, vector<int>(k, INF)); 
        dist[1][0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1}); 
        while (!pq.empty())
        {
            int wt = pq.top().first;
            int par = pq.top().second;
            pq.pop();

            if (dist[par][k - 1] < wt)
            {
                continue;
            }

            for (auto it : adj[par])
            {
                int dwt = it.second;
                int child = it.first;

                if (dist[child][k - 1] > wt + dwt)
                {
                    dist[child][k - 1] = wt + dwt;
                    pq.push({dist[child][k - 1], child});
                    sort(dist[child].begin(), dist[child].end());            }
            }
        }

        for (int i = 0; i < k; i++)
        {
            cout << (dist[n][i] == INF ? -1 : dist[n][i]) << " ";
        }
        cout << endl;
    }

    return 0;
}
