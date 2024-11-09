#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void ans(int v) {
    if (v) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int solve(vector<int>& cnt) {
    for (int i = 1e6; i >= 1; i--) {
        int mul = 0;
        for (int j = i; j <= 1e6; j += i) {
            mul += cnt[j];
        }
        if (mul >= 2) { // Check if at least two multiples of i exist
            return i;
        }
    }
    return 0;
}

signed main() {
    fast;
    int n;
    cin >> n;
    int N = 3e6 + 1; // Size of the vector for counting elements
    vector<int> v(N, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[a]++;
    }

    cout << solve(v) << endl;
    return 0;
}
