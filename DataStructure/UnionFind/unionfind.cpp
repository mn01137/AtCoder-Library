#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind() = default;
    explicit UnionFind(size_t n) : par(n), rank(n, 0), siz(n, 1)
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
            if (rank[u] < rank[v])
            {
                swap(u, v);
            }
            par[v] = u;
            if (rank[u] == rank[v])
            {
                rank[u]++;
            }
            siz[u] += siz[v];
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
    vector<int> rank;
    vector<int> siz;
};

int main()
{
    // cout << fixed << setprecision(10);
    cin.tie(0)->sync_with_stdio(0);
    int n;
    UnionFind uf(n + 1);
}