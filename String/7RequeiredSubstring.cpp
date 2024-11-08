#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int MOD = 1e9 + 7;

vector<int> solvelps(const string &s)
{
    int n = s.size();
    vector<int> lps(n);
    int len = 0;
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<vector<int>> dp;

int solve(int i, int j, const string &s, int n, vector<int> &lpst)
{
    if (i == n)
    {
        return j == s.size() ? 1 : 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (j == s.size())
    {
        return dp[i][j] = 26 * (solve(i + 1, j, s, n, lpst) % MOD);
    }
    int ct = 0;
int t;
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        t = j;
        while(true)
        {
            if(ch == s[t])
            {
                t++;
                break;
            }
            else if(t)
            {
                t = lpst[t-1];
            }
            else break;
        }
        ct += solve(i+1,t,s,n,lpst);
        ct %= MOD;

    }

    return dp[i][j] = ct; // Memoize the result
}

signed main()
{
    fast;
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> lpst = solvelps(s); // Compute the LPS array

    dp.assign(n, vector<int>(s.size() + 1, -1)); // +1 to handle j = s.size()

    int result = solve(0, 0, s, n, lpst); // Start the DP from index 0

    cout << result << endl;

    return 0;
}
