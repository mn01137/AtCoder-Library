#  グラフのライブラリ

|  Algorithm  |  Contents  |計算量|
| ---- | ----| ----|
|  [ダイクストラ法](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/Dijkstra)  |  単一始点最短経路問題を解く際に用いる. <br> 負の閉路がある場合は使えない.  |O( $\mid E\mid \log \mid V \mid$ ) |
|  [ベルマンフォード法](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/bellmanFord/bellmanFord.cpp)  |  グラフの2点間の最短距離を求めるアルゴリズム. <br> 負の閉路がある場合でも使える. |O( $\mid E\mid \mid V \mid$ ) |
|  [ワーシャルフロイド法](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/warshallFloyd/warshallFloyd.cpp)  |  グラフの全ての頂点の間の最短路を見つけるアルゴリズム. <br> 計算量は多いが負の閉路がある場合でも使える. |O( $V^3$ ) |
|  [トポロジカルソート](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/topologicalSort/topologicalSort.cpp)  |  DAGの前後関係がわかるように順番をつけてソートを行う.|O( $\mid V\mid  + \mid E \mid$ ) |
|  [強連結成分分解](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/scc/scc.cpp)  |  グラフから強連結成分(ループできる頂点集合)を求める.|O( $V+E$ ) |
