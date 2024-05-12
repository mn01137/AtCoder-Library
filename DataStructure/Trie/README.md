# Trie 木
文字列の集合を木構造として表すことで高速に検索ができるデータ構造

## 利点と欠点
### 利点
- キー検索が高速であり，長さ $ m $ のキー検索の最悪時間計算量は $ O(m) $ となる．
- 複数のキーがノードを共有するため，多数の短い文字列を格納する場合はメモリが節約できる．
- 最も長いプレフィックスをマッチするように探索を進めるため，共通キーを効率的に探せる．
- 木構造として，深さが平衡でなくてもよい．

### 欠点
- キーの順序は辞書順である必要がある．(aからzの順に検索するため)
- 入力ノード数に対して深さが極めて深くなりうる．
- 複雑なデータ構造を表す際には，工夫が必要となる．

## ソースコード

[問題 (ABC 353-E)](https://atcoder.jp/contests/abc353/tasks/abc353_e)

$ S_{1}, ... , S_{N} $ に対して，共通するprefixの個数の総和を求める問題．
Trie木を用いて，共通ノードの数を数える．

```
struct Trie_Tree
{
    int sz;
    ll ans;
    vector<int> vec;
    vector<vector<int>> pos;
    vector<int> cnt;

    Trie_Tree(int n)
    {
        sz = 0;
        ans = 0;
        vec.assign(26, -1);
        pos.reserve(n + 1);
        cnt.reserve(n + 1);
        make_node();
    }

    int make_node()
    {
        pos.push_back(vec);
        cnt.push_back(0);
        return sz++;
    }

    void add(string &s)
    {
        int now = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            int d = s[i] - 'a';
            int &nx = pos[now][d];
            if (nx == -1)
            {
                nx = make_node();
            }
            now = nx;
            ans += cnt[now];
            cnt[now]++;
        }
    }
};
```

## 参考
- [Wikipedia-トライ (データ構造)](https://ja.wikipedia.org/wiki/%E3%83%88%E3%83%A9%E3%82%A4_(%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0))
- [アルゴリズムロジック トライ木(Trie木) の解説と実装【接頭辞(prefix) を利用したデータ構造】](https://algo-logic.info/trie-tree/)
