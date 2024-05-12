#include <bits/stdc++.h>
using namespace std;

struct Trie_Tree
{
    int sz;
    long long ans;
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

int main()
{
    int n;
    cin >> n;
    Trie_Tree tr(300000);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        tr.add(s);
    }
    cout << tr.ans << endl;
}
