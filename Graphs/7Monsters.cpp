#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    queue<pair<int, int>> q;
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }
    q.push(start);

    vector<int> dx = {-1, 1, 0, 0}; // Directions: up, down, left, right
    vector<int> dy = {0, 0, -1, 1};
    string dir = "UDLR";           // Corresponding movement directions

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
                q.push({nx, ny});
                grid[nx][ny] = (grid[x][y] == 'M') ? 'M' : dir[d];
            }
        }
    }

    pair<int, int> finish = {-1, -1};
    for (int i = 0; i < n; i++) {
        if (grid[i][0] != 'M' && grid[i][0] != '.' && grid[i][0] != '#') finish = {i, 0};
        if (grid[i][m - 1] != 'M' && grid[i][m - 1] != '.' && grid[i][m - 1] != '#') finish = {i, m - 1};
    }
    for (int i = 0; i < m; i++) {
        if (grid[0][i] != 'M' && grid[0][i] != '.' && grid[0][i] != '#') finish = {0, i};
        if (grid[n - 1][i] != 'M' && grid[n - 1][i] != '.' && grid[n - 1][i] != '#') finish = {n - 1, i};
    }

    if (finish.first == -1 || finish.second == -1) {
        cout << "NO" << endl;
        return 0;
    }

    string path;
    cout << "YES" << endl;
    auto [x, y] = finish;
    while (grid[x][y] != 'A') {
        char move = grid[x][y];
        path += move;
        if (move == 'R') y--;
        else if (move == 'L') y++;
        else if (move == 'D') x--;
        else x++;
    }

    cout << path.length() << endl;
    reverse(path.begin(), path.end());
    cout << path << endl;

    return 0;
}
