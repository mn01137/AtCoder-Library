#include <bits/stdc++.h>
using namespace std;

/**
 * Prim's algorithm (with heap)
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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int cur = 0;
        vector<int> key(n, MAX_WEIGHT);
        vector<int> parent(n, -1);
        vector<bool> used(n, false);
        pq.push(make_pair(0, cur));
        key[cur] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if (used[u])
            {
                continue;
            }
            used[u] = true;
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

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> G(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> G[i][j];
        }
    }
    Prim prim(G);
    cout << prim.getSum() << endl;
}
