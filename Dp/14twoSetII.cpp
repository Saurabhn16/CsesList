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
    int sum = n * (n + 1) / 2;
    if (sum % 2)
    {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;
    int lng=1e9+7;
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <n; i++)
    {
        for (int j = sum; j >= i; j--)
        {
            {
                dp[j] += dp[j - i];
                dp[j]%=lng;
            }
        }
    }
    cout<<dp[sum]<<endl;
    return 0;
}