#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = n; i >= 0; i--)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define bit(k) (1LL << (k))
#define all(x) (x).begin(), (x).end()

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

int main()
{
    string s = "00011011";
    auto blocks = runLengthEncoding(s);
    for (auto nx : blocks)
    {
        cout << nx.first << " " << nx.second << endl;
    }
}
