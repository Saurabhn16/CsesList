// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

vector<int> prime;


void primesolve()
{
    int n = 2e6;
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0; 
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
        }
    }
}

int countdivisor(int n)
{
    map<int, int> mp;
    int ct = 0;
    for (int p : prime)
    {
        if (p * p > n)    break;
        while (n > 0 && n % p == 0)
        {
            n /= p;
            mp[p]++;
        }
    }
    if (n > 1) {
        mp[n]++;
    }

    int k = 1;
    for (auto it : mp)
    {
        k *= (it.second + 1);
    }
    return k;
}

signed main()
{
    fast;
    primesolve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countdivisor(n) << endl;
    }
    return 0;
}
