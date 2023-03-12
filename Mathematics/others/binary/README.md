# 繰り返し2乗法 (バイナリ法)

## 整数の場合
[ソースコード](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Mathematics/others/binary/binary.cpp)
```
template <class T>
T pow(T x, T n)
{
    T ans = 1;
    while (n > 0)
    {
        if (n & 1)
            ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}
```

## 行列の場合
[ソースコード](https://github.com/Nishikubo-Masato/AtCoder-Library/tree/main/Mathematics/others/binary/binary_mat.cpp)
```
template <class T>
vector<vector<T>> mat_mul(vector<vector<T>> a, vector<vector<T>> b)
{
    int n = a.size();
    vector<vector<T>> res(n, vector<T>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] = a[i][k] * b[k][j];
            }
        }
    }
}

template <class T>
vector<vector<T>> mat_pow(vector<vector<T>> a, T b)
{
    int n = a.size();
    vector<vector<T>> res(n, vector<T>(n, 0));
    for (int i = 0; i < n; i++)
    {
        res[i][i] = 1;
    }
    while (b)
    {
        if (b & 1)
        {
            res = mat_mul(res, a);
        }
        a = mat_mul(a, a);
        b >>= 1;
    }
    return res;
}
```