#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 2e5 + 1;
const int INF = 1e18; // Large value for min comparison
int v[N];
int st[4 * N]; // Segment tree array

// Build the segment tree
int build(int si, int ss, int se) {
    if (ss == se) {
        st[si] = v[ss];
        return st[si];
    }
    int mid = (ss + se) >> 1;
    return st[si] = min(build(2 * si, ss, mid), build(2 * si + 1, mid + 1, se));
}

// Query function to get the minimum value in range [l, r]
int getMin(int si, int ss, int se, int l, int r) {
    if (l > se || r < ss) return INF; // No overlap
    if (ss >= l && se <= r) return st[si]; // Complete overlap
    int mid = (ss + se) >> 1;
    return min(getMin(2 * si, ss, mid, l, r), getMin(2 * si + 1, mid + 1, se, l, r)); // Partial overlap
}

signed main() {
    fast;
    int n, q;
    cin >> n >> q;
  
    for (int i = 1; i <= n; i++) {
        cin >> v[i]; // Using 1-based indexing for convenience
    }
    build(1, 1, n);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << getMin(1, 1, n, a, b) << endl;
    }

    return 0;
}
