#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int dir(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
    {
        return (a[1] > b[1]) ? 1 : 2;
    }
    else
    {
        return (a[0] > b[0]) ? 3 : 4;
    }
}
signed main()
{
    fast;
    int t;
    cin >> t;
    vector<vector<int>> v(t, vector<int>(2, 0));
    for (int i = 0; i < t; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }

    int ct = 0;
    int prev = -1;
    for (int i = 0; i < t; i++)
    {
        int j = (i + 1) % t;
        int k = dir(v[i], v[j]);
        if ((prev == 4 && k == 2) || (prev == 2 && k == 3) || (prev == 3 && k == 1) || (prev == 1 && k == 4))
        {
            ct++;
        }
        prev = k;
    }
    cout << ct << endl;
    return 0;
}
