#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

vector<array<long long, 3>> queries;
vector<long long> answer;

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
    int query_cnt = 0;
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
        // ABC393 F
        // 置き換えた後，iの長さがクエリのRと一致している場合，dp[k] <=　Xとなる最大のkを
        // segment treeで求めに行く
        while (query_cnt < (int)queries.size())
        {
            long long R = queries[query_cnt][0];
            long long X = queries[query_cnt][1];
            long long index_num = queries[query_cnt][2];

            // iがRと一致しているか？
            if (R - 1 == i)
            {
                // dp[k] <= X となる最大のkを求める
                // Xは何番目に位置しているかを座標から二分探索
                int x = upper_bound(aval.begin(), aval.end(), X) - aval.begin();
                x++; // 1-indexed
                int k = dp.prod(0, x);
                answer[index_num] = k;
                query_cnt++;
            }
            else
            {
                // していない場合は次回以降．
                break;
            }
        }
    }

    return LIS_answer;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    queries.resize(Q);
    answer.resize(Q);
    for (int i = 0; i < Q; i++)
    {
        long long R, X;
        cin >> R >> X;
        queries[i] = {R, X, i};
    }

    // Rが小さい順にクエリを並び替え
    sort(queries.begin(), queries.end(), [&](auto a, auto b)
         { return a[0] < b[0]; });

    LIS(A);

    for (int i = 0; i < Q; i++)
    {
        cout << answer[i] << "\n";
    }
}
