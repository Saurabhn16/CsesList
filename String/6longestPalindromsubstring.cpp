#include <bits/stdc++.h>
using namespace std;

vector<int> manacher_odd(string t)
{

    int m = t.size();
    vector<int> p(m, 0); // Array to store the radius of palindrome around each center
    int c = 0, r = 0;    // Center and right boundary of the rightmost palindrome

    for (int i = 1; i < m - 1; i++)
    {
        // Mirror of i with respect to center c
        int mirror = 2 * c - i;

        if (i < r)
        {
            p[i] = min(r - i, p[mirror]); // Use the previous palindrome info if possible
        }

        // Expand the palindrome centered at i
        while (t[i + p[i] + 1] == t[i - p[i] - 1])
        {
            p[i]++;
        }

        // Update center and right boundary if the palindrome extends beyond r
        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];
        }
    }

    return p;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    string t = "";
    for (int i = 0; i < n; i++)
    {
        t += "#" + string(1, s[i]);
    }
    t += "#";
    // for (auto it : t)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    vector<int> result = manacher_odd(t);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }

    // cout << endl;
    int idx = 0;
    int mx = -1;
    for (int i = 0; i < result.size(); i++)
    {

        if (mx < result[i])
        {
            mx = result[i];
            idx = i;
        }
    }
    // cout << mx << " " << idx << endl;

    int sind = (idx-mx) / 2;
    if(mx>idx){
        sind=0;
    }
    cout << s.substr(sind, mx) << endl;
    ;

    return 0;
}
