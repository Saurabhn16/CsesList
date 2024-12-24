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
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> temp;
    vector<int> dp(n, 0);
    dp[0] = 1;
    temp.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        int k = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
        if(temp.back()<v[i]){
            temp.push_back(v[i]);
        }
        else{
            temp[k]=min(temp[k],v[i]);
        }
        dp[i]=temp.size();
    }
    cout<<dp[n-1]<<endl;
    return 0;
}