#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int MOD = 1e9+7;

// Function to calculate modular inverse using extended Euclidean method
int inverse(int i) {
    if (i == 1) return 1;
    return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}

// Function to calculate a^b % MOD using fast exponentiation
int POW(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    int temp = POW(a, b / 2);
    if (b % 2 == 0) return (temp * temp) % MOD;
    else return (((temp * temp) % MOD) * a) % MOD;
}

signed main() {
    fast;
    int n;
    cin >> n;
    int ct = 0;
    
    for (int i = 1, j; i <= n; i = j) {
        int q = n / i;
        j = n / q + 1;
        
        // Calculate a = (j - 1) * j / 2 % MOD using modular inverse of 2
        int a = (j - 1) * j % MOD;
        a = a * inverse(2) % MOD;
        
        // Calculate b = (i - 1) * i / 2 % MOD using modular inverse of 2
        int b = (i - 1) * i % MOD;
        b = b * inverse(2) % MOD;
        
        // Calculate qt = (a - b + MOD) % MOD
        int qt = (a - b + MOD) % MOD;
        
        // Update the count
        ct = (ct + q * qt) % MOD;
    }
    
    // Final division by 2 using modular inverse of 2
    cout << (ct * inverse(2)) % MOD << endl;
    return 0;
}
