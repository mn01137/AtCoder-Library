# 半分全列挙による全探索の高速化
選択するかどうかの全探索を行う場合には計算量はO( $2^N$ )となり, $N=40$ の場合には $2^{40} = 10^{12}$のため間に合わない.

$N=20$ の場合には $2^{20} = 10^{6}$となるため, 半分にしてそれぞれ独立に探索することを考える.

それぞれを全探索してしまうと $10^6 \times 10^6 = 10^{12}$となるため間に合わないが, 片方を二分探索すると O( $2^{N/2} N$ ) となるため高速化させることができる.

## 実装例
以下のような状況で、合計値が $S$ 以下となるような選び方での最大の合計値を求めたい.
- $N=8$
- 数列 ： { $31,15,11,20,13,8,5,9$ }
- $S=62$
```
int main()
{
    int n = 8;
    int s = 62;
    vector<int> num = {31, 15, 11, 20, 13, 8, 5, 9};

    // 前半をbit全探索で全列挙
    vector<int> A;
    for (int bit = 0; bit < (1 << n / 2); bit++)
    {
        int sum = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (bit & (1 << i))
            {
                sum += num[i];
            }
        }
        A.push_back(sum);
    }
    // 後半をbit全探索で全列挙
    vector<int> B;
    for (int bit = 0; bit < (1 << (n - n / 2)); bit++)
    {
        int sum = 0;
        for (int i = 0; i < (n - n / 2); i++)
        {
            if (bit & (1 << i))
            {
                sum += num[n / 2 + i];
            }
        }
        B.push_back(sum);
    }
    sort(B.begin(), B.end());
    // Aを固定して二分探索
    int ans = 0;
    for (auto a : A)
    {
        if (s - a >= 0)
        {
            ans = max(ans, a + *(upper_bound(B.begin(), B.end(), s - a) - 1));
        }
    }
    // ans = 62
    cout << ans << endl;
}
```

## 参考
- [半分全列挙による全探索の高速化 - アルゴリズムロジック](https://algo-logic.info/split-and-list/)
- [たのしい探索アルゴリズムの世界【前編：全探索、bit全探索から半分全列挙まで】](https://qiita.com/e869120/items/25cb52ba47be0fd418d6#5-%E3%81%AF%E3%82%84%E3%81%84%E6%8E%A2%E7%B4%A2%E6%B3%95%E5%8D%8A%E5%88%86%E5%85%A8%E5%88%97%E6%8C%99)
