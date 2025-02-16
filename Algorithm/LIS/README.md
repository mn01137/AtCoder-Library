# LIS(最長部分増加列)
最長部分増加列をin-place DPで $O(N \log N)$ で実装するライブラリ．

|  Algorithm  |  Contents  |
| ---- | ----|
|  [二分探索 ver.](https://github.com/mn01137/AtCoder-Library/blob/main/Algorithm/LIS/binary_search.cpp)  |  二分探索によるLISを構築  |
|  [セグメント木 ver.](https://github.com/mn01137/AtCoder-Library/blob/main/Algorithm/LIS/segment_tree.cpp)  |  セグメント木によるLISを構築  |

## コピペ用

### 二分探索 ver.
```c++
int LIS(const vector<long long> &A)
{
    int N = (int)A.size();
    long long LIS_INF = 1LL << 60;
    vector<long long> dp(N, LIS_INF);
    for (int i = 0; i < N; i++)
    {
        // dp[k] >= A[i]となる最小のイテレータ
        auto itr = lower_bound(dp.begin(), dp.end(), A[i]);

        // そこをA[i]でおきかえる
        // dp[k] : 最長部分増加列の長さがkのときの，i番目まで見た場合の一番後ろの数
        *itr = A[i];
    }

    // dp[k] < INFとなる最大のkに対して，長さk+1がLISの答え
    // 問題に合わせて調整する．
    return lower_bound(dp.begin(), dp.end(), LIS_INF) - dp.begin();
}
```

### セグメント木 ver.
```c++
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

int LIS(const vector<long long> &A)
{
    int N = (int)A.size();

    // 座標圧縮
    vector<long long> aval;
    for (int i = 0; i < N; i++)
    {
        aval.push_back(A[i]);
    }
    sort(aval.begin(), aval.end());
    aval.erase(unique(aval.begin(), aval.end()), aval.end());

    // セグメント木(区間最大)
    Segment_Tree<int> dp(N + 1, [](int a, int b)
                         { return max(a, b); }, 0);

    int LIS_answer = 0;
    for (int i = 0; i < N; i++)
    {
        // A[i]が何番目か
        int h = lower_bound(aval.begin(), aval.end(), A[i]) - aval.begin();
        ++h; // 1-indexed

        // 最大値を取得
        // a = max_{(0 <= k < A[i])} dp[k]
        int a = dp.prod(0, h);

        // update
        if (dp.get(h) < a + 1)
        {
            dp.set(h, a + 1);
            LIS_answer = max(LIS_answer, a + 1);
        }
    }

    return LIS_answer;
}
```


## 考え方
- dp[i][j] = 最初の $i$ 項のみを考えた場合の単調な部分列において，最後の要素が $A_j$ であるような場合についての，最長の長さ．

とする．
この場合， $i$ から $i+1$ への更新は以下のようになる．

- chmax(dp[i+1][j], dp[i][j]) ( $A_i$ を選ばない場合)
- chmax(dp[i+1][j], dp[i][j] + 1) ( $A_i$ を選ぶ場合，ただし $A_i > A_j$)

ここで， $A_i$ の一箇所だけ更新が発生し，それ以外の要素は全く同じになることがわかる．
そのため，in-place化によって，更新するべき所のみを二分探索 or 平衡二分木によって探索することで計算量を落とすという考え方．

具体的には，dp[i][k] $\geq a_i$ となる最小のkを二分探索によって求める．

セグメント木の場合でも考え方は同じだが，dp[i][A[j]]としたときに，A[j] $\leq 10^9$ の場合にメモリが足りないため，座標圧縮によって実現する．

## 提出例
- ABC393 F
    - [二分探索 ver.](https://atcoder.jp/contests/abc393/submissions/62848409)
    - [セグメント木　ver.](https://atcoder.jp/contests/abc393/submissions/62849419)

## 参考サイト
- [LIS でも大活躍！ DP の配列使いまわしテクニックを特集](https://qiita.com/drken/items/68b8503ad4ffb469624c#3-lis-%E3%81%AE%E8%A7%A3%E6%B3%951-%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-ver)
