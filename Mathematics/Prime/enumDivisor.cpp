#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

template <class T>
vector<T> enum_divisors(T n)
{
    vector<T> res;
    for (T i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (n / i != i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    // cout << fixed << setprecision(10);
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    const auto &res = enum_divisors(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}