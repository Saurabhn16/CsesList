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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int x, int y, vector<vector<int>> &vis, vector<string> &grid)
{
    vis[x][y] = 1;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < 4; i++)
    {
        int xd = x + dx[i];
        int yd = y + dy[i];
        if (xd >= 0 && xd < n && yd >= 0 && yd < m && vis[xd][yd] == 0 && grid[xd][yd] == '.')
        {
            dfs(xd, yd, vis, grid);
            vis[xd][yd]=1;
        }
    }
}
signed main()
{
    fast;

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0&&grid[i][j]=='.')
            {
                dfs(i, j, vis, grid);
                ct++;
            }
        }
    }
    cout << ct << endl;
    return 0;
}