#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;
vector<vector<int>> dist;

// n : 頂点数
void warshall_floyd(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    dist = vector<vector<int>>(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        dist[from][to] = cost;
    }

    warshall_floyd(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] != INF and i != j)
            {
                cout << i << "から" << j << "へのコスト: " << dist[i][j] << endl;
            }
        }
    }
}