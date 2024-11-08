#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 2e5 + 7;
vector<vector<int>> dp(N, vector<int>(3, 0));
vector<vector<int>> adj(N);

void dfs(int v, int p) {
   
    for (auto it : adj[v]) {
        if (it != p) {
            dfs(it, v);

            if (dp[v][0] < 1 + dp[it][0]) {
                dp[v][1] = dp[v][0];
                dp[v][0] = dp[it][0] + 1;
                dp[v][2] = it;
            } else {
                dp[v][1] = max(dp[v][1], 1 + dp[it][0]);
            }
        }
    }
}

void dfs1(int v, int p) {
    for (auto it : adj[v]) {
        if (it != p) {
            if (dp[v][2] == it) {
                if (dp[it][0] < dp[v][1] + 1) {
                    dp[it][1] = dp[it][0];
                    dp[it][0] = dp[v][1] + 1;
                    dp[it][2] = v;
                } else {
                    dp[it][1] = max(dp[it][1], dp[v][1] + 1);
                }
            }else {
                dp[it][1]=dp[it][0];
                dp[it][0]=dp[v][0]+1;
                dp[it][2]=v;
            }
            dfs1(it, v);
        }
    }
}

signed main() {
    fast;
    int t;
    cin >> t;

    adj.clear();
    adj.resize(t + 1);

    for (int i = 0; i < t - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    dfs1(1, -1);

    for (int i = 1; i <= t; i++) {
        cout << dp[i][0] << " ";
    }
    cout << endl;

    return 0;
}
