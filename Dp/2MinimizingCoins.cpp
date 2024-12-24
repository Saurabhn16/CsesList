#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    fast;

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int INF = 1e9 + 7;
    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i <= x; i++) {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    cout << (dp[x] == INF ? -1 : dp[x]) << endl;

    return 0;
}
