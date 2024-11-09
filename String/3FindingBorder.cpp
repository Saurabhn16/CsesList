// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
 
void ans(int v)
{
    if (v)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
 
vector<int> lps(string &p)
{
    int n = p.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
 
    while (i < n)
    {
        if (p[i] == p[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
 
signed main()
{
    fast;
 
    string p;
    cin >> p;
 
    vector<int> v = lps(p);
    vector<int> ans;
    int i = v[p.size() - 1];
 
    while (i > 0)
    {
        ans.push_back(i);
        i = v[i - 1];
    }
  
    sort(ans.begin(), ans.end());
    for (auto it : ans)
    {
        cout << it << " ";
    }
 
    cout << endl;
 
    return 0;
}

