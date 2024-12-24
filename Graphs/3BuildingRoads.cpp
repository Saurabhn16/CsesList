#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

vector<int> parent, component_size;

int find(int a)
{
    if (parent[a] != a)
        parent[a] = find(parent[a]); // Path compression
    return parent[a];
}

void union_sets(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB)
    {
        // Union by size
        if (component_size[rootA] > component_size[rootB])
            swap(rootA, rootB);
        parent[rootA] = rootB;
        component_size[rootB] += component_size[rootA];
    }
}

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

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp;
    vector<vector<int>> adj(n + 1);

    parent.resize(n + 1);
    component_size.resize(n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
 for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (auto it : vp)
    {
        int a = it.first;
        int b = it.second;
        union_sets(a, b);
    }

    vector<int> ans_nodes;
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)  {
            ans_nodes.push_back(i);
        }
    }


    if (ans_nodes.size() > 1)
    {
        cout << ans_nodes.size() - 1 << endl;
        for (int i = 1; i < ans_nodes.size(); i++)
        {
            cout << ans_nodes[0] << " " << ans_nodes[i] << endl;
        }
    }else{
        cout<<0<<endl;
    }

    return 0;
}
