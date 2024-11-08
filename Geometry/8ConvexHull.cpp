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

signed main() {
    fast;
   int a,b,c,d,e,f;
   cin>>a>>b>>c>>d>>e>>f;
   int k=(a+b+c)*(a+b+c)-(a*a)-(c*c)-(e*e);
   cout<<k<<endl;

    return 0;
}