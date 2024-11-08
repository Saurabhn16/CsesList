#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, q;
const int N = 4e5 + 1;
int seg[2 * N], a[N], s[N], en[N], st[N];
int timer = 0;
vector<int> adj[N];

int query(int i, int j, int p = 1, int l = 0, int r = n - 1)
{
    if (i > j)
    {
        return 0;
    }
    if (l >= i && r <= j)
    {
        return seg[p];
    }
    int mid = (l + r) >> 1;
    int left = query(i, min(j, mid), p * 2, l, mid);
    int right = query(max(i, mid + 1), j, p * 2 + 1, mid + 1, r);
    return left + right;
}

void update(int x, int val, int p = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        seg[p] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        update(x, val, p * 2, l, mid);
    }
    else
    {
        update(x, val, p * 2 + 1, mid + 1, r);
    }
    seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

void dfs(int s, int p)
{
    st[s] = timer++;
    for (auto c : adj[s])
    {
        if (c != p)
        {
            dfs(c, s);
        }
    }
    en[s] = timer - 1;
}

signed main() 
{
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        update(st[i], a[i]);
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            int x;
            cin >> x;
            update(st[b], x);
        }
        else
        {
            cout << query(st[b], en[b]) << endl;
        }
    }

    return 0;
}
