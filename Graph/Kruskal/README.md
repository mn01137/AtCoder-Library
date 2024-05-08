# クラスカル法
グラフ理論において重み付き連結グラフの最小全域木を求める最適化問題のアルゴリズムである．

## ソースコード
```
struct Edge
{
    int v, u;
    ll cost;

    bool operator<(const Edge &o) const
    {
        return cost < o.cost;
    }
};

template <class T>
T kruskal(int n, vector<Edge> es)
{
    sort(es.begin(), es.end());

    // UnionFind uf(n); // 0-indexed
    dsu uf(n);
    T min_cost = 0;

    for (auto &e : es)
    {
        if (!uf.same(e.v, e.u))
        {
            min_cost += e.cost;
            uf.merge(e.v, e.u);
        }
    }
    return min_cost;
}
```
### atcoder::dsu を使わない場合のUnionFind構造
```
struct UnionFind
{
    vector<int> par, sizes;

    UnionFind(int n) : par(n), sizes(n, 1)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
    }

    int find(int x)
    {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }

    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return;

        if (sizes[x] < sizes[y])
            swap(x, y);

        par[y] = x;
        sizes[x] += sizes[y];
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    int size(int x)
    {
        return sizes[find(x)];
    }
};
```

## 参考
- [Wikipedia クラスカル法](https://ja.wikipedia.org/wiki/%E3%82%AF%E3%83%A9%E3%82%B9%E3%82%AB%E3%83%AB%E6%B3%95)
- [最小全域木（クラスカル法とUnionFind）](https://dai1741.github.io/maximum-algo-2012/docs/minimum-spanning-tree/)
