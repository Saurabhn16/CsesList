// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int find(int a, vector<int> &par)
{
    if (a == par[a])
    {
        return a;
    }
    return par[a] = find(par[a], par); // Path compression
}

void union_sets(int a, int b, vector<int> &par, vector<int> &rank, int &mx)
{
    int par_a = find(a, par);
    int par_b = find(b, par);
    if (par_a != par_b)
    {
        if (rank[par_a] < rank[par_b])
        {
            par[par_a] = par_b;
            rank[par_b] += rank[par_a];
            mx = max(mx, rank[par_b]);
        }
        else
        {
            par[par_b] = par_a;
            rank[par_a] += rank[par_b];
            mx = max(mx, rank[par_a]);
        }
    }
}

signed main()
{
    fast;

    int n, m;
    cin >> n >> m;

    vector<int> par(n + 1), rank(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }

    int ct = n;
    int mx = 1;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b ;

        if (find(a, par) != find(b, par))
        {
            ct--;
            union_sets(a, b, par, rank, mx);
        }
        cout << ct << " " << mx << endl;
    }

    return 0;
}
