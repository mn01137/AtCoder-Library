# 遅延評価セグメント木

以下はACL(AtCoder Libarary)による実装を載せています．

## コンストラクタ

```
lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
```
```
vector<T> a(n);
lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
```

- モノイドの型：```S```
- ： $S \times S \rightarrow S$ を計算する関数 ```S op(S a, S b)```]
- 単位元を返す：```S e()```
- 写像の型：```F```
- $f(x)$ を返す関数：```S mapping(F f,F g)```
- $f \circ g$ を返す関数：```F composition```
- $id$ を返す関数：```F id()```

## 遅延伝搬

### 区間加算・区間最小値取得
```
using S = long long;
using F = long long;

const S INFNITY = 8e18;

S op(S a, S b){ return min(a, b); }
S e(){ return INFNITY; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }
```

### 区間変更・区間最大値取得
```
using S = long long;
using F = long long;

const S INFNITY = 8e18;
const F ID = 8e18;

S op(S a, S b){ return max(a, b); }
S e(){ return -INFNITY; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }
```

### 区間変更・区間和取得
```
struct S{
    long long val;
    int size;
};
using F = long long;

const F ID = 8e18;

S op(S a, S b){ return {a.val + b.val, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return (f != ID ? S{f*(long long)x.size, x.size} : x); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }
```

## 参考
- [AtCoder LibraryのLazy Segtreeのチートシート - ARMERIA](https://betrue12.hateblo.jp/entry/2020/09/23/005940)
