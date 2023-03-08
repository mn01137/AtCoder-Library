#include <bits/stdc++.h>
using namespace std;

vector<int> TopologicalSort(vector<vector<int>> &graph)
{
    vector<int> deg(graph.size());
    for (const auto &v : graph)
    {
        for (const auto &to : v)
        {
            deg[to]++;
        }
    }
    queue<int> q;
    // 辞書順最小のものであればpriority_queueを用いる
    for (int i = 0; i < (int)graph.size(); i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty())
    {
        /**
        if (q.size() != 1)
        {
            cout << "一位に定まらない" << endl;
        }
        */
        int from = q.front();
        q.pop();
        result.push_back(from);
        for (const auto &to : graph[from])
        {
            if (--deg[to] == 0)
            {
                q.push(to);
            }
        }
    }
    if (result.size() != graph.size())
    {
        cout << "No" << endl;
        return {};
    }
    return result;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
    }
    vector<int> result = TopologicalSort(graph);
    for (auto v : result)
    {
        cout << v << " ";
    }
}