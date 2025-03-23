# ローリングハッシュ

## 実装
```
using mint = modint998244353;

struct RollingHash
{
    string S;
    int N;
    const int char_size = 26;
    vector<mint> hash_table;

    RollingHash(string S) : S(S)
    {
        N = S.size();
        hash_table.resize(N + 1);
        hash_table[0] = 0;
        rep(i, N)
        {
            hash_table[i + 1] = hash_table[i] * char_size + S[i] - 'A';
        }
    }

    mint get(int l, int r)
    {
        return hash_table[r] - hash_table[l] * mint(char_size).pow(r - l);
    }
};
```

## 参考
- [ABC398 F - ABCBA](https://atcoder.jp/contests/abc398/tasks/abc398_f)