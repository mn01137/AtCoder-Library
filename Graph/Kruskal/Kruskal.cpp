#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    UnionFind uf(n); // 0-indexed
    // atcoder::dsu uf(n);
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

int main()
{
    // n : ノード番号
    // m : query
    int n = 5, m = 8;

    // input
    vector<Edge> edges(m);
    edges[0] = {0, 1, 10};
    edges[1] = {0, 3, 5};
    edges[2] = {1, 2, 1};
    edges[3] = {1, 3, 1000};
    edges[4] = {1, 4, 500};
    edges[5] = {2, 3, 100};
    edges[6] = {2, 4, 10000};
    edges[7] = {3, 4, 5000};

    // kruskal
    ll cost = kruskal<ll>(n, edges);

    // 516が出力される
    cout << "最小全域木のコスト : " << cost << endl;
}
