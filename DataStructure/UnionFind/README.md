# UnionFind構造体
```
class UnionFind
{
public:
    UnionFind() = default;
    explicit UnionFind(size_t n) : _n(n), par(n), rank(n, 0), siz(n, 1)
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
        assert(0 <= u and u < _n);
        assert(0 <= v and v < _n);
        u = root(u), v = root(v);
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
    vector<vector<int>> groups()
    {
        vector<int> root_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++)
        {
            root_buf[i] = root(i);
            group_size[root_buf[i]]++;
        }
        vector<vector<int>> result(_n);
        for (int i = 0; i < _n; i++)
        {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++)
        {
            result[root_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int> &v)
                           { return v.empty(); }),
            result.end());
        return result;
    }

private:
    int _n;
    vector<int> par, rank, siz;
};
```
