# ダイクストラ法

## Note
- **辺に負のコストがある場合には使用できない.**
使いたい場合はベルマンフォード法などの他の手法を検討する.
- ヒープを使った場合の計算量はO( $\mid E\mid \log \mid V \mid$ ) であり, 
愚直に実装した場合はO( $V^2$ )となる.
**$E$ の値が異常に大きい場合**は後者の方が早くなることに注意する.

## 基本的な実装
[ソースコード](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/Dijkstra/dijkstra1.cpp)

```
// 辺の情報
struct Edge
{
    int to; //行き先
    int cost; //コスト
};
// {distance, from}
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
```

## 最短経路を再構築するための実装
[ソースコード](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/Dijkstra/dijkstra2.cpp)
```
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
```

## 参考記事
- [ダイクストラ法｜競プロのための標準 C++ - Zenn](https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/dijkstra)
- [ダイクストラ法による単一始点最短経路を求めるアルゴリズム](https://algo-logic.info/dijkstra/)