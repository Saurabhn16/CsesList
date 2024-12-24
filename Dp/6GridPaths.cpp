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
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    int lng = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    if (grid[0][0] == '.')
    {
        dp[1][1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i - 1][j - 1] == '*')
            {
                dp[i][j] = 0;
                continue;
            }
            if (i > 1)
            {
                dp[i][j] += dp[i - 1][j];
            }
            dp[i][j] %= lng;
            if (j > 1)
            {
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= lng;
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
