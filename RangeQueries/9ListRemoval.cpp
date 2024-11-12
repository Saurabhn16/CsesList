#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int N = 2e5 + 1;
const int INF = 1e18;
int v[N];
int st[4 * N];

// Function to combine segment tree nodes (sum in this case)
int solve(int a, int b) {
    return a + b;
}

// Function to build the segment tree
int build(int si, int ss, int se) {
    if (ss == se) {
        st[si] = v[ss];
        return st[si];
    }
    int mid = (ss + se) >> 1;
    return st[si] = solve(build(2 * si, ss, mid), build(2 * si + 1, mid + 1, se));
}

// Function to update the segment tree
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

int getSum(int si, int ss, int se, int l, int r) {
    if (l > se || r < ss) 
        return 0;
    if (ss >= l && se <= r) 
        return st[si];
    int mid = (ss + se) >> 1;
    return solve(getSum(2 * si, ss, mid, l, r), getSum(2 * si + 1, mid + 1, se, l, r)); // Partial overlap
}

signed main() {
    fast;
    int n, q;
    cin >> n;
    q=n;
    vector<int> ans(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> ans[i];
        v[i] = 1;
    }
    build(1, 1, n);

    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        int lo = 1;
        int hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int total = getSum(1, 1, n, 1, mid);
            if (total >= c) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans[lo] << " ";
        v[lo] = 0;
        update(1, 1, n, lo, v[lo]);
    }

    cout << endl;
    return 0;
}
