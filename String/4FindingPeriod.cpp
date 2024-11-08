#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void ans(int v) {
    if (v) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

// Function to compute Z-array
vector<int> zfun(const string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

signed main() {
    fast;
    string s;
    cin >> s;
    vector<int> v = zfun(s);
    vector<int> ans;
    
    // Finding positions where the suffix matches the prefix
    for (int i = 0; i < v.size(); i++) {
        if (i + v[i] == v.size()) {
            ans.push_back(i);
        }
    }
    ans.push_back(v.size());
    // Output the positions
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}
