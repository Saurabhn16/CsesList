#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 2e5 + 1;
const int INF = -1e18;
int v[N];
int st[4 * N];

int solve(int a, int b) {
    return max(a, b);
}

int build(int si, int ss, int se) {
    if (ss == se) {
        st[si] = v[ss];
        return st[si];
    }
    int mid = (ss + se) >> 1;
    return st[si] = solve(build(2 * si, ss, mid), build(2 * si + 1, mid + 1, se));
}

void update(int si, int ss, int se, int idx, int val) {
    if (ss == se) {
        st[si] = val;
        return;
    }
    int mid = (ss + se) >> 1;
    if (idx <= mid) {
        update(2 * si, ss, mid, idx, val);
    } else {
        update(2 * si + 1, mid + 1, se, idx, val);
    }
    st[si] = solve(st[2 * si], st[2 * si + 1]);
}

int ind(int l, int r, int si, int m) {
    if (st[si] < m) {
        return 0; 
    }
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    if (st[2 * si] >= m) {
        return ind(l, mid, 2 * si, m);
    } else {
        return ind(mid + 1, r, 2 * si + 1, m);
    }
}

signed main() {
    fast;
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    build(1, 1, n);

    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        int k = ind(1, n, 1, c);
        if (k == 0) {
            cout << "0 ";  } else {
            cout << k << " ";
            v[k] -= c;
            update(1, 1, n, k, v[k]);
        }
    }

    cout << endl;
    return 0;
}
