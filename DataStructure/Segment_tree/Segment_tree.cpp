#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    const int INF = 1 << 30;
    Segment_Tree<int> seg(
        A, [&](int a, int b)
        { return max(a, b); },
        -INF);
    while (Q--)
    {
        int T;
        cin >> T;
        if (T == 1)
        {
            int X, V;
            cin >> X >> V;
            X--;
            seg.set(X, V);
        }
        else if (T == 2)
        {
            int L, R;
            cin >> L >> R;
            L--;
            cout << seg.prod(L, R) << endl;
        }
        else
        {
            int L, V;
            cin >> L >> V;
            L--;
            int idx = seg.max_right([&](int x) -> bool
                                    { return V > x; },
                                    L);

            cout << idx + 1 << endl;
        }
    }
}
