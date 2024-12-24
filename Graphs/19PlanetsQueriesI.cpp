#include <bits/stdc++.h>
using namespace std;
 
const int MAX_N = 200000;
const int MAX_LOG = 32;
int teleporters[MAX_N];
int dp[MAX_N][MAX_LOG];
 
void preprocess(int n)
{
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = teleporters[i] - 1;
    }
 
    for (int j = 1; j < MAX_LOG; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}
 
int query(int x, long long k)
{
    x -= 1;
    for (int j = 0; j < MAX_LOG; ++j)
    {
        if (k & (1LL << j))
        {
            x = dp[x][j];
        }
    }
    return x + 1;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin >> n >> q;
 
    for (int i = 0; i < n; ++i)
    {
        cin >> teleporters[i];
    }
 
    preprocess(n);
 
    while (q--)
    {
        int x;
        long long k;
        cin >> x >> k;
        cout << query(x, k) << "\n";
    }
 
    return 0;
}
