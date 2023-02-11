#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind() = default;
    explicit UnionFind(size_t n) : par(n), siz(n, 1)
    {
        iota(par.begin(), par.end(), 0);
    }
    int root(int pos)
    {
        if (par[pos] == pos)
            return pos;
        return (par[pos] = root(par[pos]));
    }
    void unite(int u, int v)
    {
        u = root(u);
        v = root(v);
        if (u != v)
        {
            if (siz[u] < siz[v])
            {
                swap(u, v);
            }
            siz[u] += siz[v];
            par[v] = u;
        }
    }
    bool issame(int u, int v)
    {
        return (root(u) == root(v));
    }
    int size(int pos)
    {
        return siz[root(pos)];
    }

private:
    vector<int> par;
    vector<int> siz;
};

int main()
{
    // cout << fixed << setprecision(10);
    cin.tie(0)->sync_with_stdio(0);
    int n;
    UnionFind uf(n + 1);
}