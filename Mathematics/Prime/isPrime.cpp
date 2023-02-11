#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

template <class T>
bool isprime(T n)
{
    if (n == 1)
        return true;
    for (T i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    // cout << fixed << setprecision(10);
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    if (isprime(n))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}