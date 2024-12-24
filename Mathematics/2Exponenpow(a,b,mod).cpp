// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
int pow(int a, int b, int m) {
    a %= m; // Ensuring a is within modulo range
    int res = 1;
    while (b > 0) {
        if (b & 1) // If b is odd
            res = res * a % m;
        a = a * a % m; // Square a
        b >>= 1;       // Divide b by 2
    }
    return res;
}

signed main()
{
    fast;
    int t;
    cin >> t; // Number of test cases
    int mod = 1e9 + 7;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        // Calculate (b^c) % (mod - 1) using modular exponentiation
        // This ensures we handle large exponents correctly
        int d = pow(b, c, mod - 1); 

        // Calculate (a^d) % mod
        cout << pow(a, d, mod) << endl;
    }
    return 0;
}
