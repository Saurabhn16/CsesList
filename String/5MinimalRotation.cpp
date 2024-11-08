#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 62;
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;
    s += s;
    int n = s.size();
    int ans = 0;
    int i = 0;
    while (i < n / 2) {
        ans = i;
        int k = i, j = i + 1;
        while (j < n && s[j] >= s[k]) {
            if (s[j] == s[k]) {
                k++;
            }
            if (s[j] > s[k]) {
                k = i;
            }
            j++;
        }
        while (i <= k) {
            i += j - k;
        }
    }
    cout << s.substr(ans, n / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    for (int i = 1; i <= t; i++) {
        solve();
        cout << '\n';
    }

    return 0;
}
