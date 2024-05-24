# フォードファルカーソン法

## アルゴリズムの流れ
1. フロー $ f $ を $ 0 $ とする
2. source (入口) から sink (出口) までの増加可能経路 $ p $ が残余ネットワーク $ G_{f} $ に存在する間は以下を繰り返す．
    - フロー $ f $ を $ p $ に沿って深さ優先探索によって増やす．
3. フロー $ f $ の流量 $ \mid f \mid $ を返す．

## ソースコード

```
struct Edge
{
    int rev, from, to, cap;
};

class FordFulkerson
{
public:
    vector<vector<Edge>> G;
    vector<bool> visited;

    int size = 0;
    FordFulkerson(int n)
    {
        G.resize(n);
        visited.resize(n);
        size = n;
    }

    void add_edge(int u, int v, int cost)
    {
        int u_vID = G[u].size();
        int v_uID = G[v].size();
        G[u].emplace_back(Edge{v_uID, u, v, cost});
        G[v].emplace_back(Edge{u_vID, v, u, 0});
    }

    int dfs(int pos, int goal, int F)
    {
        if (pos == goal)
            return F;

        visited[pos] = true;

        for (auto &e : G[pos])
        {
            if (e.cap == 0 or visited[e.to])
                continue;

            int flow = dfs(e.to, goal, min(F, e.cap));

            if (flow > 0)
            {
                e.cap -= flow;
                G[e.to][e.rev].cap += flow;
                return flow;
            }
        }

        return 0;
    }

    // 頂点sから頂点tまでの最大フローの総流量を返す
    int maxFlow(int s, int t)
    {
        int totalFlow = 0;
        while (true)
        {
            visited.assign(size, false);
            int F = dfs(s, t, 1 << 30);
            if (F == 0)
                break;
            totalFlow += F;
        }
        return totalFlow;
    }
};
```
