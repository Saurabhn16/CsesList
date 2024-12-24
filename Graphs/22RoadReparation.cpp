// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int find(int a, vector<int> &par)
{
    if (a == par[a])
    {
        return a;
    }
    return par[a] = find(par[a], par);
}

void union_sets(int a, int b, vector<int> &par, vector<int> &rank)
{
    int par_a = find(a, par);
    int par_b = find(b, par);
    if (par_a != par_b)
    {

        if (rank[par_a] < rank[par_b])
        {
            par[par_a] = par_b;
        }
        else if (rank[par_a] > rank[par_b])
        {
            par[par_b] = par_a;
        }
        else
        {
            par[par_b] = par_a;
            rank[par_a]++;
        }
    }
}

signed main()
{
    fast;
   
    {
        int n, m;
        cin >> n >> m;

        vector<int> par(n + 1), rank(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }

        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            pq.push({c, {a, b}});
        }

        int ans = 0;
        while (!pq.empty())
        {
            int wt = pq.top().first;
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            pq.pop();

            if (find(a, par) != find(b, par))
            {
                ans += wt;
                union_sets(a, b, par, rank);
            }
        }
int ct=0;
for(int i=1;i<=n;i++){
    if(find(i,par)==i){
        ct++;
    }
}
if(ct>1){
    cout<<"IMPOSSIBLE"<<endl;
}else{
        cout << ans << endl;}
    }
    return 0;
}
