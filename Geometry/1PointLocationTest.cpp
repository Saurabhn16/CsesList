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

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int crossProduct = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

        if (crossProduct == 0)
        {
            cout << "TOUCH" << endl;
        }
        else if (crossProduct > 0)
        {
            cout << "LEFT" << endl;
        }
        else
        {
            cout << "RIGHT" << endl;
        }
    }
    return 0;
}