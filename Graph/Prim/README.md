# プリム法

## ソースコード

### ヒープを使わない場合
- 計算量：$ O(V^{2})$

```
/**
 * Prim's algorithm (without heap)
 * input : adjacency matrix (graph)
 * output : sum of weight in Minimum Spanning Tree
 * order : O(V^2) (V : number of vertexes)
 */
struct Prim
{
public:
    Prim(vector<vector<int>> const &Graph)
    {
        n = (int)Graph.size();
        minCost.assign(n, MAX_WEIGHT);
        used.assign(n, false);
        sum = 0;
        minCost[0] = 0; // 0-indexed
        while (true)
        {
            int v = -1;
            for (int u = 0; u < n; u++)
            {
                if (!used[u] and (v == -1 || minCost[u] < minCost[v]))
                {
                    v = u;
                }
            }
            if (v == -1)
            {
                break;
            }
            used[v] = true;
            sum += minCost[v];
            for (int u = 0; u < n; u++)
            {
                if (Graph[v][u] != -1)
                {
                    minCost[u] = min(minCost[u], Graph[v][u]);
                }
            }
        }
    }

    int getSum()
    {
        return sum;
    }

private:
    const int MAX_WEIGHT = 1e9;
    int sum;
    int n;
    vector<int> minCost;
    vector<bool> used;
};
```

### ヒープを使う場合
