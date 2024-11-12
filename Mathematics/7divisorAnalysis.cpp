#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int power(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int modInverse(int a, int mod) {
    int g = __gcd(a, mod);
    if (g != 1) {
        return -1; // No modular inverse exists
    } else {
        return power(a, mod - 2, mod);
    }
}

signed main() {
    fast;
    int n;
    cin >> n;
    const int MOD = 1e9 + 7;

    vector<int> x(n), k(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> k[i];
    }

    // Calculating number of divisors
    int No = 1;
    for (int i = 0; i < n; i++) {
        No = (No * (k[i] + 1)) % MOD;
    }

    // Calculating sum of divisors
    int sum = 1;
    for (int i = 0; i < n; i++) {
        int num = (power(x[i], k[i] + 1, MOD) - 1 + MOD) % MOD;
        int deno = modInverse(x[i] - 1, MOD);
        int geoSum = (num * deno) % MOD;
        sum = (sum * geoSum) % MOD;
    }

    // Calculating product of divisors
    int pi = 1;
    for (int i = 0; i < n; i++) {
        pi = (pi * power(x[i], k[i], MOD)) % MOD;
    }

    // Product of divisors is pi raised to the power of No/2 modulo MOD
    int prod = power(pi, No / 2, MOD);

    cout << No << " " << sum << " " << prod << endl;

    return 0;
}
