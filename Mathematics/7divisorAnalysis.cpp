#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Function to compute a^b % mod using binary exponentiation
int power(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Modular inverse using Fermat's little theorem
int modInverse(int a, int mod) {
    return power(a, mod - 2, mod);
}

signed main() {
    fast;
    int n;
    cin >> n;

    vector<pair<int, int>> factors(n);   for (int i = 0; i < n; i++) {
        cin >> factors[i].first >> factors[i].second;
    }

    int divisorCount = 1; 
    int divisorSum = 1; 
    int productPower = 1; 
    for (auto &[prime, exp] : factors) {
        divisorCount = (divisorCount * (exp + 1)) % MOD;

        int numerator = (power(prime, exp + 1, MOD) - 1 + MOD) % MOD;
        int denominator = modInverse(prime - 1, MOD);
        int geoSum = (numerator * denominator) % MOD;
        divisorSum = (divisorSum * geoSum) % MOD;

       productPower = (productPower * power(prime, exp * (exp + 1) / 2, MOD)) % MOD;
    }

    cout << divisorCount << " " << divisorSum << " " << productPower << endl;
    return 0;
}
