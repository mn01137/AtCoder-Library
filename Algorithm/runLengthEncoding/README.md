# ランレングス圧縮

"AAABBCC" $\rightarrow$ "A3B2C2" に変換する

```
vector<pair<char, int>> runLengthEncoding(string s)
{
    vector<pair<char, int>> res;
    int cnt = 0;
    char c;
    rep(i, s.size())
    {
        if (i == 0)
        {
            c = s[i];
            cnt++;
        }
        else
        {
            if (c == s[i])
            {
                cnt++;
            }
            else
            {
                res.push_back({c, cnt});
                c = s[i];
                cnt = 1;
            }
        }
    }
    if (cnt > 0)
    {
        res.push_back({c, cnt});
    }
    return res;
}
```
