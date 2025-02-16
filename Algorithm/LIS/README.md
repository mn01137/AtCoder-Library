# LIS(最長部分増加列)
最長部分増加列をin-place DPで $O(N \log N)$ で実装するライブラリ．

|  Algorithm  |  Contents  |
| ---- | ----|
|  [二分探索 ver.]()  |  二分探索によるLISを構築  |

## コピペ用

### 二分探索 ver.
```c++
int LIS(const vector<long long> &A)
{
    int N = (int)A.size();
    long long LIS_INF = 1LL << 60;
    vector<long long> dp(N, LIS_INF);
    for (int i = 0; i < N; i++)
    {
        // dp[k] >= A[i]となる最小のイテレータ
        auto itr = lower_bound(dp.begin(), dp.end(), A[i]);

        // そこをA[i]でおきかえる
        // dp[k] : 最長部分増加列の長さがkのときの，i番目まで見た場合の一番後ろの数
        *itr = A[i];
    }

    // dp[k] < INFとなる最大のkに対して，長さk+1がLISの答え
    // 問題に合わせて調整する．
    return lower_bound(dp.begin(), dp.end(), LIS_INF) - dp.begin();
}
```


## 考え方
- dp[i][j] = 最初の $ i $ 項のみを考えた場合の単調な部分列において，最後の要素が$ A_j $ であるような場合についての，最長の長さ．

とする．
この場合， $ i $ から $ i+1 $ への更新は以下のようになる．

- chmax(dp[i+1][j], dp[i][j]) ( $ A_i $ を選ばない場合)
- chmax(dp[i+1][j], dp[i][j] + 1) ( $ A_i $ を選ぶ場合，ただし $ A_i > A_j $)

ここで， $ A_i $ の一箇所だけ更新が発生し，それ以外の要素は全く同じになることがわかる．
そのため，in-place化によって，更新するべき所のみを二分探索 or 平衡二分木によって探索することで計算量を落とすという考え方．

具体的には，dp[i][k] $ \geq a_i $ となる最小のkを二分探索によって求める．

## 提出例
- [ABC393-F(二分探索 ver.)](https://atcoder.jp/contests/abc393/submissions/62848409)

## 参考サイト
- [LIS でも大活躍！ DP の配列使いまわしテクニックを特集](https://qiita.com/drken/items/68b8503ad4ffb469624c#3-lis-%E3%81%AE%E8%A7%A3%E6%B3%951-%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-ver)