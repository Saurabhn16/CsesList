// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Binary lifting
vector<int> tree[200001];
int anc[200001][21];

void dfs(int v, int p) {
    anc[v][0] = p;
    for (int i = 1; i <= 20; i++) {
        if (anc[v][i - 1] != -1) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
        } else {
            anc[v][i] = -1;
        }
    }
    for (auto ch : tree[v]) {
        dfs(ch, v);
    }
}

int query(int node, int k) {
    if (k == 0) return node;
    if (node == -1) return -1;
    
    for (int i = 20; i >= 0; i--) {
        if (k & (1 << i)) {
            return query(anc[node][i], k - (1 << i));
        }
    }
    return node;
}

signed main() {
    fast;
    int n, q;
    cin >> n >> q;
    
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }
    
    dfs(1, -1);
    
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        cout << query(x, k) << endl;
    }
    return 0;
}
