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

    int x;
    cin >> x;
    int n = 9;
    const int MOD = 1e9 + 7;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        coins[i] = i + 1;
       
    }

    vector<int> dp(x + 1, MOD);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        string a=to_string(i);
         for(char c:a){
            int digit=c-'0';
            if(digit!=0){
                dp[i]=min(dp[i],dp[i-digit]+1);
            }
         }
          dp[i] %= MOD;
    }
  

    cout << (dp[x] == MOD ? -1 : dp[x]) << endl;
    return 0;
}
