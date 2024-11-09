#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int N = 2e5 + 1;
const int INF = 0;
int v[N];
int st[4 * N];

int solve(int a, int b)
{
    return a^b;
}
int build(int si, int ss, int se)
{
    if (ss == se)
    {
        st[si] = v[ss];
        return st[si];
    }
    int mid = (ss + se) >> 1;
    return st[si] = solve(build(2 * si, ss, mid), build(2 * si + 1, mid + 1, se));
}
void update(int si, int ss, int se,int idx,int val)
{
    if (ss == se)
    {
        st[si] = val;
        return;
    }
    int mid = (ss + se) >> 1;
    if (idx <= mid)
    {
        update(2 * si, ss, mid, idx, val);
    }
    else
    {

        update(2 * si + 1, mid + 1, se, idx, val);
    }
    st[si] = solve(st[2 * si], st[2 * si + 1]);
}

int getMin(int si, int ss, int se, int l, int r)
{
    if (l > se || r < ss)
        return INF;
    if (ss >= l && se <= r)
        return st[si];
    int mid = (ss + se) >> 1;
    return solve(getMin(2 * si, ss, mid, l, r), getMin(2 * si + 1, mid + 1, se, l, r)); // Partial overlap
}

signed main()
{
    fast;
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    build(1, 1, n);

    for (int i = 0; i < q; i++)
    {
        int c, a, b;
        cin >> a >> b;
        // if (c == 1)
        // {
        //     update(1,1,n,a, b);
        // }
        // else
        {
            cout << getMin(1, 1, n, a, b) << endl;
        }
    }

    return 0;
}
