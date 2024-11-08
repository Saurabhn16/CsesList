// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Binary lifting
vector<int> tree[200001];
int anc[200001][21];
int dep[200001];

void dfs(int v, int p) {
    anc[v][0] = p;
    dep[v] = (p == -1) ? 0 : dep[p] + 1;
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

int lca(int a, int b) {
    if (dep[a] > dep[b]) {
        swap(a, b);
    }
    int d = dep[b] - dep[a];
    for (int i = 0; i <= 20; i++) {
        if (d & (1 << i)) {
            b = anc[b][i];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = 20; i >= 0; i--) {
        if (anc[a][i] != anc[b][i]) {
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];
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
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}
