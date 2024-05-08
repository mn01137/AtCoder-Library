# セグメント木 (Segment Tree)

## 関数オブジェクト
- op : 演算子
    - 最小の場合：`[&](int a,int b){return min(a,b)}`
    - 最大の場合：`[&](int a,int b){return max(a,b)}`
- e : 単位元
    - $x \cdot e = e \cdot x = x$ を満たす $e$

## 計算量
- コンストラクタ
    - 配列が与えられている場合は， $O(N)$ で初期化できる．
    - `seg.set(x)`で入力した場合は $O(N \log N)$ となる．
- 更新
    - 更新する場所は木の高さ分あるので， $O(f_{op}(N)\log N)$
- 区間取得 (`seg.prod(l,r)`)
    - $l=r$ のとき単位元が返る．
    - 参照する場所は木の高さ分あるので， $O(f_{op}(N)\log N)$
- 全要素の総積を取得 (`seg.all_prod()`)
    - 完全ニ分木の根に当たるため， $O(1)$

## ソースコード

### Segment Tree
```
template <class Monoid>
struct Segment_Tree
{
    using F = function<Monoid(Monoid, Monoid)>;

    int N;
    int sz;
    vector<Monoid> seg;

    F op;
    Monoid e;

    Segment_Tree() {}
    Segment_Tree(int n, const F &_op, const Monoid &_e)
    {
        init(n, _op, _e);
    }
    Segment_Tree(const vector<Monoid> &v, const F &_op, const Monoid &_e)
    {
        init((int)v.size(), _op, _e);
        build(v);
    }

    void init(int n, const F &_op, const Monoid &_e)
    {
        N = n;
        op = _op;
        e = _e;
        sz = 1;
        while (sz < N)
            sz <<= 1;
        seg.assign(2 * sz, _e);
    }

    void build(const vector<Monoid> &v)
    {
        for (int i = 0; i < N; i++)
        {
            seg[sz + i] = v[i];
        }
        for (int k = sz - 1; k >= 0; k--)
        {
            seg[k] = op(seg[2 * k], seg[2 * k + 1]);
        }
    }

    int size() const
    {
        return N;
    }

    void set(int n, const Monoid &x)
    {
        int k = n + sz;
        seg[k] = x;
        while (k >>= 1)
        {
            seg[k] = op(seg[2 * k], seg[2 * k + 1]);
        }
    }

    Monoid get(int k) const
    {
        return seg[k + sz];
    }

    // get [a, b), a and b are 0-indexed, O(log N)
    Monoid prod(int a, int b) const
    {
        Monoid ml = e;
        Monoid mr = e;
        for (int l = a + sz, r = b + sz; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ml = op(ml, seg[l++]);
            if (r & 1)
            {
                mr = op(seg[--r], mr);
            }
        }
        return op(ml, mr);
    }

    Monoid all_prod() const
    {
        return seg[1];
    }

    int max_right(const function<bool(Monoid)> f, int l = 0)
    {
        if (l == N)
        {
            return N;
        }
        l += sz;
        Monoid sum = e;
        do
        {
            while (l % 2 == 0)
            {
                l >>= 1;
            }
            if (!f(op(sum, seg[l])))
            {
                while (l < sz)
                {
                    l *= 2;
                    if (f(op(sum, seg[l])))
                    {
                        sum = op(sum, seg[l]);
                        l++;
                    }
                }
                return l - sz;
            }
            sum = op(sum, seg[l]);
            l++;
        } while ((l & -l) != l);
        return N;
    }

    // debug
    friend ostream &operator<<(ostream &s, const Segment_Tree &seg)
    {
        for (int i = 0; i < seg.size(); ++i)
        {
            s << seg[i];
            if (i != seg.size() - 1)
                s << " ";
        }
        return s;
    }
};
```

### メイン文 (区間最大)
```
vector<int> A; // input
const int INF = 1 << 30;
Segment_Tree<int> seg(A, [&](int a, int b){ return max(a, b); },-INF);
```
- `Segment_Tree<型> seg(vector, operation, identity element)

## モノイドとは？
以下の条件を満たす組 $(S,op,e)$ をモノイドという．

1. 演算 $op$ が集合 $S$ に閉じている．
2. $op(x,y) = x \cdot y$ は結合法則 $(x \cdot y) \cdot z = x \cdot (y \cdot z)$ を満たす．
3. $S$ に単位元 $e$ が存在する．

## 参考文献
- [【Segtree編】AtCoder Library 解読 〜Pythonでの実装まで〜](https://qiita.com/AkariLuminous/items/32cbf5bc3ffb2f84a898)
- [AtCoder Library Practice Contest J - Segment Tree (1D)](https://drken1215.hatenablog.com/entry/2023/11/14/033300)
