#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> pre(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '*') {
                pre[i][j] = 1;
            }
            if (i > 0) {
                pre[i][j] += pre[i - 1][j];
            }
            if (j > 0) {
                pre[i][j] += pre[i][j - 1];
            }
            if (i > 0 && j > 0) {
                pre[i][j] -= pre[i - 1][j - 1];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--; // Convert to 0-based indexing
        int result = pre[c][d];
        if (a > 0) {
            result -= pre[a - 1][d];
        }
        if (b > 0) {
            result -= pre[c][b - 1];
        }
        if (a > 0 && b > 0) {
            result += pre[a - 1][b - 1];
        }
        cout << result << endl;
    }

    return 0;
}
