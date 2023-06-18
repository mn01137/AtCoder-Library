# フェニック木(Fenwick tree (binary indexed tree,BIT))

```
template <typename T>
struct fenwick_tree
{
public:
    fenwick_tree(int n) : _n(n), data(n, 0) {}

    void add(int i, T x)
    {
        i++;
        while (i <= _n)
        {
            data[i - 1] += x;
            i += (i & -i);
        }
    }

    T range_sum(int l, int r)
    {
        return sum(r) - sum(l);
    }

private:
    int _n;
    vector<T> data;

    T sum(int i)
    {
        T s = 0;
        while (i > 0)
        {
            s += data[i - 1];
            i -= (i & -i);
        }
        return s;
    }
};
```
