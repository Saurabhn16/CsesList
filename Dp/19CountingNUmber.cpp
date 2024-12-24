#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int MAX_DIGITS = 20;
int dp[MAX_DIGITS][2][2][10];

int solve(int i, int tight, int zero, int prev, string &s)
{
    if (i == s.size())
    {
        return 1;
    }

    if (dp[i][tight][zero][prev + 1] != -1)
    {
        return dp[i][tight][zero][prev + 1];
    }

    int limit = (tight ? s[i] - '0' : 9);
    int res = 0;

    for (int d = 0; d <= limit; d++)
    {
        if (prev == -1 || prev != d || zero)
        {
            int newTight = tight & (d == limit);
            int newZero = (zero && d == 0) ? 1 : 0;
            res += solve(i + 1, newTight, newZero, d, s);
        }
    }

    return dp[i][tight][zero][prev + 1] = res;
}


int countValidNumbers(string &num)
{
    memset(dp, -1, sizeof(dp));
    return solve(0, 1, 1, -1, num);}

signed main()
{
    fast;
    int s1, t1;
    cin >> s1 >> t1;

    string s = to_string(s1 - 1); 
    string t = to_string(t1);   
    int high = countValidNumbers(t);

    
    int low = countValidNumbers(s);
int ct = high - low;

    cout << ct << endl;

    return 0;
}
