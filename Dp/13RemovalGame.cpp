// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

vector<vector<int>> dp;

int solve(int i, int end, vector<int> &v)
{
    if (i > end)
        return 0;
    if (dp[i][end] != -1)
        return dp[i][end];

    int ct = (v.size() - 1 - end) + i;

    if (ct % 2 == 0)
    {
        int front = v[i] + solve(i + 1, end, v);
        int back = v[end] + solve(i, end - 1, v);
        return dp[i][end] = max(front, back);
    }
    else
    {
        int front = solve(i + 1, end, v);
        int back = solve(i, end - 1, v);
        return dp[i][end] = min(front, back);
    }
}

signed main()
{
    fast;
    int n;
    cin >> n;
    vector<int> v(n);
    dp.assign(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int result = solve(0, n - 1, v);
    cout << result << endl;

    return 0;
}
