#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

struct Edge
{
    int to;
    int cost;
};
using Graph = vector<vector<Edge>>;

void Dijkstra(const Graph &Graph, vector<ll> &distances, int startIndex, int targetIndex, vector<int> &path)
{
    vector<int> p(distances.size(), -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace((distances[startIndex] = 0), index);
    while (!pq.empty())
    {
        const ll distance = pq.top().first;
        const int from = pq.top().second;
        pq.pop();
        if (distances[from] < distance)
        {
            continue;
        }
        for (const auto &edge : Graph[from])
        {
            const ll d = (distances[from] + edge.cost);
            if (d < distances[edge.to])
            {
                p[edge.to] = from;
                pq.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }
    if (distances[targetIndex] != INF)
    {
        for (int i = targetIndex; i != -1; i = p[i])
        {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
    }
}

int main()
{
}