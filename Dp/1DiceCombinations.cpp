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
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    int lng = 1e9 + 7;
    for (int i = 0; i <= n; i++)
    {

        for (int j = 1; j <= 6; j++)
        {
            if (j <= i)
            {
                dp[i] += dp[i - j];
            }
            dp[i] %= lng;
        }
    }

    cout << dp[n] << endl;
    return 0;
}