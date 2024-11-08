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
    int n, q;
    cin >> n >> q;
    vector<int> pre(n + 1, 0);
    vector<int> v(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        pre[i + 1] = sum;
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << pre[b] - pre[a - 1] << endl;
    }

    return 0;
}