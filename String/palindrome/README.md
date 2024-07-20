# 回文判定

回文を判定する．

## ソースコード

```
bool isPalindrome(string s,int k)
{
    for (int j = 0; j < k / 2; ++j)
    {
        if (s[i + j] != s[i + k - 1 - j])
        {
            return false;
        }
    }
    return false;
}
```
