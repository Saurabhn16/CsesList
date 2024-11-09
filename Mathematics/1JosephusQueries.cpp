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
int solve(int n, int k)
{

    if (n == 1)
    {
        return 1;
    }
    if (k <= (n + 1) / 2)
    {

        if (2 * k > n)
        {
            return (2 * k) % n;
        }
        else
        {
            return 2 * k;
        }
    }

    long long temp = solve(n / 2, k - (n + 1) / 2);

    if (n % 2 == 1)
    {
        return 2 * temp + 1;
    }
    return 2 * temp - 1;
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k)  << endl;
    }
    return 0;
}