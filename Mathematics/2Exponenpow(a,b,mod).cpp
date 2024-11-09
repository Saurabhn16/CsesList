// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);



int  pow(int  a, int  b, int  m) {
    a %= m;
    int  res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

signed main()
{
    fast;
    int t;
    cin >> t; 
    int mod = 1e9 + 7;
    while (t--)
    {
        int a, b,c;
        cin >> a >> b>>c;
        int d=pow(b,c,mod-1); 
        cout << pow(a, d, mod) << endl;
    }
    return 0;
}
