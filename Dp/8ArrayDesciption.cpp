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
        printf("YES\n");
    else
        printf("NO\n");
}
 
// Memoization table
map<pair<int, int>, int> dp;
 
int solve(int i, int val, int m,vector<int> &v)
{
  
    if (i == v.size())z
        return 1;
   if (dp.find({i, val}) != dp.end())
        return dp[{i, val}];
 
    int res = 0;
 
    if (v[i] != 0)
    {
        res = solve(i + 1, v[i],m, v);
    }
    else
    {
      if (val == -1)
        {
            res = 3 * solve(i + 1, val,m, v);
        }
        else
        {
            for (int j = -1; j <= 1; j++)
            {
                if(val-j>=1&&val<=m)
                res += solve(i + 1, val - j,m, v);
            }
        }
    }
 
    return dp[{i, val}] = res;
}
 
signed main()
{
    fast;
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
 
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
 
    dp.clear(); // Clear the memoization table
    int k = solve(0, -1,m, v);
 
    cout << k << "\n"; // Print the result
 
    return 0;
}