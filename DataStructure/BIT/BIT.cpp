#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

template <typename T>
struct fenwick_tree
{
public:
    fenwick_tree(int n) : _n(n), data(n, 0) {}

    void add(int i, T x)
    {
        i++;
        while (i <= _n)
        {
            data[i - 1] += x;
            i += (i & -i);
        }
    }

    T range_sum(int l, int r)
    {
        return sum(r) - sum(l);
    }

private:
    int _n;
    vector<T> data;

    T sum(int i)
    {
        T s = 0;
        while (i > 0)
        {
            s += data[i - 1];
            i -= (i & -i);
        }
        return s;
    }
};

int main()
{
    int n;
    cin >> n;
    fenwick_tree<int> fw(n);
}
