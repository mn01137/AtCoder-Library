# 遅延評価セグメント木

```
class segment_tree
{
private:
    int sz;
    vector<int> seg, lazy;
    void eval(int k)
    {
        if (k < sz)
        {
            lazy[k * 2] = max(lazy[k * 2], lazy[k]);
            lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
        }
        seg[k] = max(seg[k], lazy[k]);
        lazy[k] = 0;
    }
    void update(int a, int b, int x, int k, int l, int r)
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
    int range_max(int a, int b, int k, int l, int r)
    {
        eval(k);
        if (r <= a or b <= l)
        {
            return 0;
        }
        else if (a <= l and r <= b)
        {
            return seg[k];
        }
        else
        {
            int vl = range_max(a, b, k * 2, l, (l + r) / 2);
            int vr = range_max(a, b, k * 2 + 1, (l + r) / 2, r);
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
        seg = vector<int>(sz * 2, 0);
        lazy = vector<int>(sz * 2, 0);
    }
    void updte(int l, int r, int x)
    {
        update(l, r, x, 1, 0, sz);
    }
    int range_max(int l, int r)
    {
        return range_max(l, r, 1, 0, sz);
    }
};
```

## 参考
[例題 029-Long Bricks (競プロ典型90問)](https://atcoder.jp/contests/typical90/tasks/typical90_ac)

[アルゴリズムロジック セグメント木を徹底解説！](https://algo-logic.info/segment-tree/)
