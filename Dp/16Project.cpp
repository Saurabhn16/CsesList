#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

struct Project
{
    int start, end, reward;
};

bool compare(Project a, Project b)
{
    return a.end < b.end;
}

int solve(vector<Project> &projects, int n)
{
    vector<int> dp(n);
    dp[0] = projects[0].reward;

    vector<int> end_times(n);
    for (int i = 0; i < n; i++)
    {
        end_times[i] = projects[i].end;
    }

    for (int i = 1; i < n; i++)
    {
        int include = projects[i].reward;

        int idx = lower_bound(end_times.begin(), end_times.end(), projects[i].start) - end_times.begin() - 1;

        if (idx >= 0)
        {
            include += dp[idx];
        }

        dp[i] = max(dp[i - 1], include);
    }

    return dp[n - 1];
}

signed main()
{
    fast;

    int n;
    cin >> n;
    vector<Project> projects(n);

    for (int i = 0; i < n; i++)
    {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects.begin(), projects.end(), compare);
    cout << solve(projects, n) << endl;
    return 0;
}
