// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<string> st(n);
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> st[i];
        int num = 0;
        for (int j = 0; j < m; j++) {
            if (st[i][j] == '1') {
                num |= (1 << j);
            }
        }
        v[i] = num;
    }

    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int xo = v[i] ^ v[j];
            int hd = __builtin_popcountll(xo);
            mn = min(mn, hd);
        }
    }

    cout << mn << endl;
    return 0;
}
