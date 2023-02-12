# 探索処理のライブラリ

|  Algorithm  |  Contents  |計算量|
| ---- | ----| ----|
|  [bit全探索](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Search/bitSearch/bitSearch.cpp)  |  部分集合を全パターン列挙する  |O( $2^N$ ) |
|  [順列全探索](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Search/permutation/permutation.cpp)  | 集合の順列を全列挙する  |O( $N!\times N$ ) |
|  [二分探索](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Search/binarySearch/binarySearch.cpp)  | 二分探索によりindexを求める  |O( $\log(N)$ ) |


## Note
### ```std::set``` における二分探索について
```
int key;
std::set<int> st;
std::binary_search(st.begin(),st.end(),key);
```
としてしまった場合は計算量が O( $N$ ) になってしまう点に注意が必要.

計算量をO( $\log(N)$ )にするためには,
```
int key;
std::set<int> st;
st.binary_search(key);
```
上記のように```std::set```に標準搭載されている二分探索を使用する.
詳しくは[公式リファレンス](https://cpprefjp.github.io/reference/algorithm/binary_search.html)を参照.
