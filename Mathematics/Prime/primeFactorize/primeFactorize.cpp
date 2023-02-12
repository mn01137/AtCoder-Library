#include <bits/stdc++.h>
using namespace std;

template <class T>
vector<pair<T, T>> prime_factorize(T n)
{
    vector<pair<T, T>> res;
    for (T i = 2; i * i <= n; ++i)
    {
        if (n % i != 0)
            continue;
        T ex = 0;

        while (n % i == 0)
        {
            ++ex;
            n /= i;
        }
        res.push_back({i, ex});
    }
    if (n != 1)
        res.push_back({n, 1});
    return res;
}

int main()
{
    long long n;
    cin >> n;
    const auto &res = prime_factorize(n);
    for (auto p : res)
    {
        cout << p.first << "^" << p.second << endl;
    }
}