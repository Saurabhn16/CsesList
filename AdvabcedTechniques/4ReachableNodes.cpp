#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int maxN = 50001;
bitset<maxN> ans[maxN];
vector<int> adj[maxN];
vector<int> in(maxN);

signed main()
{
    fast;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        in[a]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            ans[i].set(i);
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            ans[v] |= ans[u];
            in[v]--;
            if (in[v] == 0)
            {
                ans[v].set(v);
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].count() << " ";
    }
    cout << endl;

    return 0;
}
