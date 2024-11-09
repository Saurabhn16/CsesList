// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int MOD = 1e9 + 7;
 
struct Trie
{
    int val;
    vector<Trie *> child;
 
    Trie() : val(0)
    {
        child.resize(26, nullptr);
    }
};
 
Trie *root = new Trie();
 
void insert(const string &s)
{
    Trie *temp = root;
    for (char ch : s)
    {
        if (!temp->child[ch - 'a'])
        {
            temp->child[ch - 'a'] = new Trie();
        }
        temp = temp->child[ch - 'a'];
    }
    temp->val = 1;
}
 
int solve(int i, Trie *temp, const string &s, vector<int> &dp)
{
    if (i == s.size())
        return 1;
    if (dp[i] != -1)
        return dp[i];
    int ct = 0;
    Trie *current = temp;
 
    for (int j = i; j < s.size(); ++j)
    {
        if (!current->child[s[j] - 'a'])
            break;
        current = current->child[s[j] - 'a'];
 
        if (current->val == 1)
        {
            ct = (ct + solve(j + 1, root, s, dp)) % MOD;
        }
    }
 
    return dp[i] = ct;
}
 
signed main()
{
    fast;
    string s;
    int k;
    cin >> s >> k;
 
    vector<string> v(k);
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
        insert(v[i]);
    }
 
    vector<int> dp(s.size(), -1);
    int ct = solve(0, root, s, dp);
 
    cout << ct % MOD << endl;
    return 0;
}
