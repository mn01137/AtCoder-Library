# N進数からM進数に変換

## ソースコード
```
string ntom(const string str, const int n, const int m)
{
    unsigned long sum = 0;
    for (char c : str)
    {
        sum = sum * n + (c - '0');
    }
    string res = "";
    do
    {
        int num = sum % m;
        res = static_cast<char>(num + '0') + res;
        sum /= m;
    } while (sum);
    return res;
}
```
