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
    vector<int> v(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    int lng = sum + 1;
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    vector<int> ans;
    for (int coin : v)
    {
        for (int j = lng; j >= coin; j--)
        {
            if (dp[j - coin])
            {
                dp[j] = true;
            }
        }
    }
    for (int i = 1; i < lng; i++)
    {
        if (dp[i])
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}