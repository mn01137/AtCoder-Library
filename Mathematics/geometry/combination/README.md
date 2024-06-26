# コンビネーション

## 二項係数mod素数の高速化
modint構造体をpairとすること．

- nPk：順列
- nCk：組み合わせ
- nHk：組み分け
```
template <typename T, int MAX_>
struct Comb
{
    vector<T> fac, ifac;
    Comb()
    {
        fac.resize(MAX_, 1);
        ifac.resize(MAX_, 1);
        for (int i = 1; i <= MAX_; i++)
            fac[i] = fac[i - 1] * i;
        ifac[MAX_ - 1] = T(1) / fac[MAX_ - 1];
        for (int i = MAX_ - 2; i >= 1; i--)
            ifac[i] = ifac[i + 1] * T(i + 1);
    };
    T aPb(int a, int b)
    {
        if (b < 0 || a < b)
            return T(0);
        return fac[a] * ifac[a - b];
    }
    T aCb(int a, int b)
    {
        if (b < 0 || a < b)
            return T(0);
        return fac[a] * ifac[a - b] * ifac[b];
    }
    T nHk(int n, int k)
    {
        if (n == 0 && k == 0)
            return T(1);
        if (n <= 0 || k < 0)
            return 0;
        return aCb(n + k - 1, k);
    }
};
Comb<mint, 5000> com;
```

## 使用例
- [ABC132 D - Blue and Red Balls](https://atcoder.jp/contests/abc132/tasks/abc132_d)

- [提出したソースコード](https://atcoder.jp/contests/abc132/submissions/41830741)

## 参考
- [二項係数 mod 素数を高速に計算する方法 [累積和, フェルマーの小定理, 繰り返し二乗法, コンビネーション, 10^9+7]](https://blog.hamayanhamayan.com/entry/2018/06/06/210256)

- [組み分けに関する説明でわかりやすかったもの](https://integraldx.info/division-into-groups-3822)
