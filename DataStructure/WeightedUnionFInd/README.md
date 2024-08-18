# 重み付きUnionFind

- ```merge(x, y, w)``` : weight(y) = weight(x) + w となるように x と y をマージする．
- ```issame(x, y)``` : x と y が同じグループにいるかどうかを判定する．
- ```diff(x, y)``` : x と y とが同じグループにいるとき、weight(y) - weight(x) をリターンする．

```
template <typename T>
class WeightedUnionFind
{
public:
    WeightedUnionFind(int n)
    {
        N = n;
        par.resize(n);
        rank.resize(n);
        diff_weight.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i, rank[i] = 0, diff_weight[i] = 0;
        }
    }

    int root(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        else
        {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    T weight(int x)
    {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }

    bool merge(int x, int y, T w)
    {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (rank[x] < rank[y])
            swap(x, y), w = -w;
        if (rank[x] == rank[y])
            ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    T diff(int x, int y)
    {
        return weight(y) - weight(x);
    }

private:
    int N;
    vector<int> par;
    vector<int> rank;
    vector<T> diff_weight;
};
```

## 出題
- [ABC 328 F - Good Set Query](https://atcoder.jp/contests/abc328/tasks/abc328_f)
    - [AC 提出コード](https://atcoder.jp/contests/abc328/submissions/56858274)

## 参考文献
- [重み付き Union-Find とそれが使える問題のまとめ、および、牛ゲーについて](https://qiita.com/drken/items/cce6fc5c579051e64fab)
