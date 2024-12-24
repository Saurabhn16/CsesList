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
   
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        vector<int> cnt(n + 1, 0);
        vector<int> in(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            in[b]++;
        }
        cnt[1] = 1;
        queue<int>q;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }
        int lng=1e9+7;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto  it:adj[a]){
                in[it]--;
                 cnt[it]+=cnt[a];
                 cnt[it]%=lng;
                if(in[it]==0){
                   
                    q.push(it);
                }

            }
        }
         cout<<cnt[n]<<endl;
    }
    return 0;
}