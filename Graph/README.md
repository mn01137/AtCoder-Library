#  グラフのライブラリ

## 最短経路問題
|  Algorithm  |  Contents  |計算量|
| ---- | ----| ----|
|  [ダイクストラ法](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/Dijkstra)  |  単一始点最短経路問題を解く際に用いる. <br> 負の閉路がある場合は使えない.  |$O( \mid E\mid \log \mid V \mid ) $|
|  [ベルマンフォード法](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/bellmanFord/bellmanFord.cpp)  |  グラフの2点間の最短距離を求めるアルゴリズム. <br> 負の閉路がある場合でも使える. |$O( \mid E\mid \cdot \mid V \mid )$ |
|  [ワーシャルフロイド法](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/warshallFloyd/warshallFloyd.cpp)  |  グラフの全ての頂点の間の最短路を見つけるアルゴリズム. <br> 計算量は多いが負の閉路がある場合でも使える. |$O( V^3 )$ |


## 最小全域木
|  Algorithm  |  Contents  |計算量|
| ---- | ----| ----|
|  [クラスカル法](Kruskal/)  | 重み付き連結グラフの最小全域木を構成する．    |  $O(E \log V)$ |
|  [プリム法](Prim/)  |  隣接行列から最小全域木を構成する．  | $O(V^{2})$ or $(E \log V)$  |

## 最大流最小カット
|  Algorithm  |  Contents  |計算量|
| ---- | ----| ----|
|  [フォードファルカーソン法](https://github.com/mn01137/AtCoder-Library/tree/main/Graph/fordFulkerson)  | フローネットワークにおける最大フローを求める．   |  $O(F \mid E \mid)$  ( $F$ : dfsの繰り返し回数)|

## その他
|  Algorithm  |  Contents  |計算量|
| ---- | ----| ----|
|  [トポロジカルソート](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/topologicalSort/topologicalSort.cpp)  |  DAGの前後関係がわかるように順番をつけてソートを行う.|$O( \mid V\mid  + \mid E \mid )$ |
|  [強連結成分分解](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Graph/scc/scc.cpp)  |  グラフから強連結成分(ループできる頂点集合)を求める.|$O( V+E )$ |
