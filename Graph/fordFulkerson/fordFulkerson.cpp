#include <bits/stdc++.h>
using namespace std;

// AtCoder Beginner Contest 091
// C - 2D Plane 2N Points
// 2部マッチング問題
// https://atcoder.jp/contests/abc091/tasks/arc092_a

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

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i] >> d[i];
    }

    FordFulkerson ff(2 * n + 2);

    int start = 2 * n;
    int end = 2 * n + 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] < c[j] and b[i] < d[j])
            {
                ff.add_edge(i, n + j, 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        ff.add_edge(start, i, 1);
        ff.add_edge(i + n, end, 1);
    }

    cout << ff.maxFlow(start, end) << endl;
}
