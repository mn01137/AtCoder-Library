#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

template <class E>
struct csr
{
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>> &edges)
        : start(n + 1), elist(edges.size())
    {
        for (auto e : edges)
        {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++)
        {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges)
        {
            elist[counter[e.first]++] = e.second;
        }
    }
};

struct scc_graph
{
public:
    explicit scc_graph(int n) : _n(n) {}
    void add_edge(int from, int to)
    {
        edges.push_back({from, {to}});
    }

    pair<int, vector<int>> scc_ids()
    {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void
        {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++)
            {
                auto to = g.elist[i].to;
                if (ord[to] == -1)
                {
                    self(self, to);
                    low[v] = min(low[v], low[to]);
                }
                else
                {
                    low[v] = min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v])
            {
                while (true)
                {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v)
                        break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++)
        {
            if (ord[i] == -1)
                dfs(dfs, i);
        }
        for (auto &x : ids)
        {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    vector<vector<int>> scc()
    {
        auto ids = scc_ids();
        int group_num = ids.first;
        vector<int> counts(group_num);
        for (auto x : ids.second)
            counts[x]++;
        vector<vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++)
        {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++)
        {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

private:
    int _n;
    struct edge
    {
        int to;
    };
    vector<pair<int, edge>> edges;
};

int main()
{
    // cout << fixed << setprecision(10);
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    scc_graph g(n);
}
