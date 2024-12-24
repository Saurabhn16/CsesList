#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

signed main()
{
    fast;
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

    vector<int> vis(n + 1, 0);
    queue<int> q;
    q.push(1);
    vector<int> par(n + 1, 0);
    vis[1] = 1;
    int ct = 0;
    int bol=0;

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            int temp = q.front();
            if(temp==n){bol=1;
            break;}
            q.pop();
            for (auto it : adj[temp])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    par[it] = temp;
                    q.push(it);
                }
            }
        }
        if(bol){
            break;
        }
        ct++;
    }

    if (bol)
    {
        vector<int> ans;
        int pr = n;
        while (pr != 1)
        {
            ans.push_back(pr);
            pr = par[pr];
        }
        ans.push_back(1);
        cout << ans.size() << endl;

        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
