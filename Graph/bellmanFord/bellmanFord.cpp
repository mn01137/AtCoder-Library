#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;

struct Edge
{
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};
vector<vector<Edge>> graph;
vector<int> dist;

// If negative cycle include, return true.
// n : 頂点数
// s : 開始頂点
bool bellman_ford(int n, int s)
{
    dist = vector<int>(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int v = 0; v < n; v++)
        {
            for (int k = 0; k < graph[v].size(); k++)
            {
                Edge e = graph[v][k];
                if (dist[v] != INF and dist[e.to] > dist[v] + e.cost)
                {
                    dist[e.to] = dist[v] + e.cost;
                    if (i == n - 1)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    graph = vector<vector<Edge>>(n);
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(Edge(to, cost));
    }
    bellman_ford(n, 0);
    for (int i = 1; i < n; i++)
    {
        if (dist[i] != INF)
        {
            cout << "0から" << i << "へのコスト: " << dist[i] << endl;
        }
    }
}