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
        vector<int> in(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            in[b]++;
            adj[a].push_back(b);
        }
        int ct = 0;
        queue<int> q;
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
           
            if (in[i] == 0)
            {
                q.push(i);
                v.push_back(i);
            }
        }

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int par = q.front();

                q.pop();
                for (auto it : adj[par])
                {
                    in[it]--;
                    if (in[it] == 0)
                    {
                        v.push_back(it);
                        q.push(it);
                    }
                }
            }
            ct++;
        }
if(v.size()==n){
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;}
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}