#include <bits/stdc++.h>
using namespace std;
#define int long long
#define md 1000000007
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);


int exp(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

signed main() {
    fast;
    int n;
    cin >> n;

    int ans = 0;
    int sq = sqrt(n);
    int inv2 = exp(2, md - 2, md);
    for (int i = 1; i <= sq; i++) {
        int l = n / (i + 1) + 1; 
        int r = n / i;         
        int x = (r - l + 1) % md;

      
        ans = (ans + x * ((l + r) % md) % md * inv2 % md * i % md) % md;
    }

   
    for (int i = 1; i <= n / (sq + 1); i++) {
        ans = (ans + (n / i) * i % md) % md;
    }

    cout << ans << "\n";
    return 0;
}
