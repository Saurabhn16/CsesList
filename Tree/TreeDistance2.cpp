// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 2e5 + 1;
int n;
vector<int> tree[N];
int subtreeAns[N];
int ans[N];
int subtreeSize[N];


void preprocessing(int v, int p) {
    int ct = 1;
    subtreeAns[v] = 0;
    for (int child : tree[v]) {
        if (child != p) {
            preprocessing(child, v);
            ct += subtreeSize[child];
            subtreeAns[v] += subtreeSize[child] + subtreeAns[child];
        }
    }
    subtreeSize[v] = ct;
}

void dfs(int v, int p, int par_ans, int n) {
    ans[v] = subtreeAns[v] + (par_ans + (n - subtreeSize[v]));
    for (int child : tree[v]) {
        if (child != p) {
            dfs(child, v, ans[v] - (subtreeAns[child] + subtreeSize[child]), n);
        }
    }
}

signed main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    preprocessing(1, 0);
    dfs(1, 0, 0, n);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
