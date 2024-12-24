#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char st[4] = {'U', 'D', 'R', 'L'};

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
    string shortest_path = "";

    queue<pair<int, pair<int, string>>> q; // {x, {y, path}}
    bool found = false;

    // Find 'A' and start BFS
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                q.push({i, {j, ""}});
                vis[i][j] = 1;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    int bol = 0;
    // Perform BFS
    while (!q.empty())
    {
        auto [x, p] = q.front();
        auto [y, path] = p;
        q.pop();

        if (grid[x][y] == 'B')
        {
            shortest_path = path;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int xd = x + dx[i];
            int yd = y + dy[i];

            if (xd >= 0 && xd < n && yd >= 0 && yd < m && vis[xd][yd] == 0 && (grid[xd][yd] == '.' || grid[xd][yd] == 'B'))
            {
                vis[xd][yd] = 1;
                q.push({xd, {yd, path + st[i]}});
                if (grid[xd][yd] == 'B')
                {
                    shortest_path = path + st[i];
                    bol = 1;
                    break;
                }
            }
        }
        if (bol)
        {
            break;
        }
    }

    if (!shortest_path.empty())
    {
        cout << "YES\n";
        cout << shortest_path.size() << "\n";
        cout << shortest_path << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
