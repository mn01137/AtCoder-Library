# エラトステネスの篩

- $N$ 以下の素数を全て求めるためのアルゴリズム
- $N$ 以下の整数集合から，合成数をふるい落とす操作を繰り返す．

## ソースコード
```
vector<bool> eratostenes(int n)
{
    vector<bool> isprime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = 2; i * j <= n; j++)
            {
                isprime[i * j] = false;
            }
        }
    }
    return isprime;
}
```


## 計算量の解析
2でふるい落とすために $\frac{N}{2}$ 回，3でふるい落とすために $\frac{N}{3}$ 回，と繰り返すと，計算量は以下のようになる．

$$ \sum_{p<\sqrt{N}} \frac{N}{p} = \frac{N}{2} + \frac{N}{3} + \frac{N}{5} + \dots $$

調和級数の発散スピードは $\log N$ であり，素数の逆数の和の発散スピードは $\log \log N$ である．

そのため，計算量は，$ O(N \log \log N) $ となる．

## 参考
- [アルゴ式 エラトステネスのふるいとは](https://algo-method.com/descriptions/64)
- [学びタイムズ エラトステネスのふるいとその計算量](https://manabitimes.jp/math/992)
- [学びタイムズ 素数の逆数和が発散することの証明](https://manabitimes.jp/math/920)
