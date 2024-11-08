#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
const int MAXN = 800005;
long long segf[MAXN] = {0}, segb[MAXN] = {0};
long long pw[200005];

class SegmentTree {
public:
    long long* seg;
    int n;

    SegmentTree(int size, long long* segRef) {
        seg = segRef;
        n = size;
    }

    void updateRange(int ss, int se, int v, int index, int val) {
        if (ss > se || index < ss || index > se) return;
        if (ss == se) {
            seg[v] = val;
            return;
        }
        int mid = ss + (se - ss) / 2;
        if (index > mid)
            updateRange(mid + 1, se, 2 * v + 1, index, val);
        else
            updateRange(ss, mid, 2 * v, index, val);
        seg[v] = (seg[2 * v + 1] + seg[2 * v] * pw[se - mid] % MOD) % MOD;
    }

    void update(int index, int val) {
        updateRange(1, n, 1, index, val);
    }

    pair<long long, int> queryRange(int ss, int se, int qs, int qe, int v) {
        if (qs > se || qe < ss) return {0, 0};
        if (qs <= ss && se <= qe) return {seg[v], se - ss + 1};
        int mid = ss + (se - ss) / 2;
        auto left = queryRange(ss, mid, qs, qe, 2 * v);
        auto right = queryRange(mid + 1, se, qs, qe, 2 * v + 1);
        long long hashValue = (left.first * pw[right.second] + right.first) % MOD;
        return {hashValue, left.second + right.second};
    }

    long long query(int qs, int qe) {
        return queryRange(1, n, qs, qe, 1).first;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // For multiple test cases if needed

    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        pw[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pw[i] = (pw[i - 1] * 26) % MOD;
        }

        SegmentTree forwardHash(n, segf), reverseHash(n, segb);

        for (int i = 0; i < n; ++i) {
            forwardHash.update(i + 1, s[i] - 'a' + 1);
            reverseHash.update(n - i, s[i] - 'a' + 1);
        }

        for (int i = 0; i < q; ++i) {
            int type;
            cin >> type;

            if (type == 1) {
                int index;
                char ch;
                cin >> index >> ch;
                forwardHash.update(index, ch - 'a' + 1);
                reverseHash.update(n - index + 1, ch - 'a' + 1);
            } else if (type == 2) {
                int l, r;
                cin >> l >> r;
                long long frontHash = forwardHash.query(l, r);
                long long revHash = reverseHash.query(n - r + 1, n - l + 1);

                if (frontHash == revHash)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }

    return 0;
}
