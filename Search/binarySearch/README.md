# 二分探索

```
int binary_search(int key)
{
    int left = 0, right = (int)a.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

```

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