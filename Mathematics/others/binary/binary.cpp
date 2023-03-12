#include <bits/stdc++.h>
using namespace std;

template <class T>
T pow(T x, T n)
{
    T ans = 1;
    while (n > 0)
    {
        if (n & 1)
            ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

template <class T>
T pow_mod(T x, T n, T mod)
{
    T ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ans *= x;
            ans = (ans + mod) % mod;
        }
        x *= x;
        x = (x + mod) % mod;
        n >>= 1;
    }
    return ans;
}

int main()
{
    long long x, n;
    cin >> x >> n;
    cout << pow(x, n) << endl;
    return 0;
}