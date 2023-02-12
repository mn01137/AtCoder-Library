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

void Dijkstra(const Graph &Graph, vector<ll> &distances, int index)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace((distances[index] = 0), index);
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
                pq.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }
}

int main()
{
}