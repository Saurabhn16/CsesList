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

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int lng = 1e9 + 7;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (auto it : coins)
    {
        for (int i = 0; i <= x; i++)
        {
            if (it <= i)
            {
                dp[i] += dp[i - it];
            }
            dp[i] %= lng;
        }
    }

    cout << dp[x] << endl;

    return 0;
}
