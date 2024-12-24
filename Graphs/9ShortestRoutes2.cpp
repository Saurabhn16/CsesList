// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int INF = 1e18; // Large value for unreachable distances

signed main()
{
    fast;

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        dp[a][b] = min(dp[a][b], wt);
        dp[b][a] = min(dp[b][a], wt);
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (dp[a][b] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dp[a][b] << endl;
        }
    }

    return 0;
}
