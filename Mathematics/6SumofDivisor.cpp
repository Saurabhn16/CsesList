#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int pow_mod(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

signed main() {
    fast;
    int n;
    cin >> n;
    int ct = 0;
    int mod = 1e9 + 7;
    for (int i = 1, j; i <= n; i = j) {
        int q = n / i;
        j = n / q + 1;
     int a = ((j - 1) * j ) % mod; 
        int b = ((i - 1) * i ) % mod; 
        a = (a * pow_mod(2, mod - 2, mod)) % mod;
        b = (b * pow_mod(2, mod - 2, mod)) % mod;
        
        int qt = (a - b + mod) % mod;
        ct = (ct + q * qt) % mod;
    }
    cout << ct /2<< endl;
    return 0;
}
