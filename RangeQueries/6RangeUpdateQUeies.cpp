#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
private:
    vector<long long> tree, lazy;
    int n;

   void buildTree(const vector<long long> &arr, int node, int start, int end)
    {
        if (start == end)
        {
         tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node, start, mid);
            buildTree(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

      void propagate(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
          tree[node] += (end - start + 1) * lazy[node]; // Range update
            if (start != end)
            {
               lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;  }
    }

    void updateRange(int node, int start, int end, int l, int r, long long value)
    {
        propagate(node, start, end);
        if (start > r || end < l)
        {
            return;
        }
        if (start >= l && end <= r)
        {
          
            tree[node] += (end - start + 1) * value;
            if (start != end)
            {
                lazy[2 * node] += value;
                lazy[2 * node + 1] += value;
            }
            return;
        }
    
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, value);
        updateRange(2 * node + 1, mid + 1, end, l, r, value);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }


    long long queryPoint(int node, int start, int end, int idx)
    {
        propagate(node, start, end);
        if (start == end)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
        {
            return queryPoint(2 * node, start, mid, idx);
        }
        else
        {
            return queryPoint(2 * node + 1, mid + 1, end, idx);
        }
    }

public:
    SegmentTree(const vector<long long> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        buildTree(arr, 1, 0, n - 1);
    }

    void updateRange(int l, int r, long long value)
    {
        updateRange(1, 0, n - 1, l, r, value);
    }

    long long queryPoint(int idx)
    {
        return queryPoint(1, 0, n - 1, idx);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegmentTree segTree(arr);

    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b;
            long long u;
            cin >> a >> b >> u;
            a--;
            b--;
            segTree.updateRange(a, b, u);
        }
        else if (type == 2)
        {
            int k;
            cin >> k;
            k--;
            cout << segTree.queryPoint(k) << endl;
        }
    }

    return 0;
}
