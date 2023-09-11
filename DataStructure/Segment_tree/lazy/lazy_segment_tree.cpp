#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

template <typename T>
class segment_tree
{
private:
    int sz;
    T val;
    vector<T> seg, lazy;
    void eval(int k)
    {
        if (k < sz)
        {
            lazy[k * 2] = max(lazy[k * 2], lazy[k]);
            lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
        }
        seg[k] = max(seg[k], lazy[k]);
        lazy[k] = val;
    }
    void update(int a, int b, T x, int k, int l, int r)
    {
        eval(k);
        if (a <= l and r <= b)
        {
            lazy[k] = x;
            eval(k);
        }
        else if (a < r and l < b)
        {
            update(a, b, x, k * 2, l, (l + r) / 2);     // left child
            update(a, b, x, k * 2 + 1, (l + r) / 2, r); // right child
            seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
        }
    }
    T range_max(int a, int b, int k, int l, int r)
    {
        eval(k);
        if (r <= a or b <= l)
        {
            return val;
        }
        else if (a <= l and r <= b)
        {
            return seg[k];
        }
        else
        {
            T vl = range_max(a, b, k * 2, l, (l + r) / 2);
            T vr = range_max(a, b, k * 2 + 1, (l + r) / 2, r);
            return max(vl, vr);
        }
    }

public:
    segment_tree() : sz(0), seg(), lazy(){};
    segment_tree(int n)
    {
        sz = 1;
        while (sz < n)
            sz *= 2;
        val = 0;
        seg = vector<T>(sz * 2, 0);
        lazy = vector<T>(sz * 2, 0);
    }
    void init(int n, T v)
    {
        sz = 1;
        while (sz < n)
            sz *= 2;
        val = v;
        seg.resize(sz * 2, val);
        lazy.resize(sz * 2, val);
    }
    void update(int l, int r, T x)
    {
        update(l, r, x, 1, 0, sz);
    }
    T range_max(int l, int r)
    {
        return range_max(l, r, 1, 0, sz);
    }
};

int main()
{
    int n;
    cin >> n;
    segment_tree<int> seg(n);
}
