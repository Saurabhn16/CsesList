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
    string s, t;
    cin >> s >> t;
    if(s.size()<t.size()){
        swap(s,t);
    }
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e5 + 7));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<m;j++){
        dp[0][j]=j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout << dp[n][m] << endl;
    return 0;
}