// saurabh_1610
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
 
vector<int> lps(string &p) {
    int n = p.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
 
    while (i < n) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
 
signed main() {
    fast;
    string s;
    string p;
 
    cin >> s >> p;
 
    vector<int> lpsArray = lps(p); // renamed for clarity
 
    int j = 0;
    int ct = 0;
 
    for (int i = 0; i < s.size();) { // note: i is not incremented inside the if
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
            if (j) {
                j = lpsArray[j - 1];
            } else {
                i++;
            }
        }
 
        if (j == p.size()) {
            ct++;
            j = lpsArray[j - 1];
        }
    }
 
    cout << ct << endl;
 
    return 0;
}

