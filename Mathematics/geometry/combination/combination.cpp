#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

template <int MOD>
struct modint
{
    static const int Mod = MOD;
    unsigned x;
    modint() : x(0) {}
    modint(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    modint(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    modint &operator+=(modint that)
    {
        if ((x += that.x) >= MOD)
            x -= MOD;
        return *this;
    }
    modint &operator-=(modint that)
    {
        if ((x += MOD - that.x) >= MOD)
            x -= MOD;
        return *this;
    }
    modint &operator*=(modint that)
    {
        x = (unsigned long long)x * that.x % MOD;
        return *this;
    }
    modint &operator/=(modint that) { return *this *= that.inverse(); }
    modint operator+(modint that) const { return modint(*this) += that; }
    modint operator-(modint that) const { return modint(*this) -= that; }
    modint operator*(modint that) const { return modint(*this) *= that; }
    modint operator/(modint that) const { return modint(*this) /= that; }
    modint inverse() const
    {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b)
        {
            long long t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        return modint(u);
    }
    bool operator==(modint that) const { return x == that.x; }
    bool operator!=(modint that) const { return x != that.x; }
    modint operator-() const
    {
        modint t;
        t.x = x == 0 ? 0 : Mod - x;
        return t;
    }
};
template <int MOD>
ostream &operator<<(ostream &st, const modint<MOD> a)
{
    st << a.get();
    return st;
};
template <int MOD>
modint<MOD> operator^(modint<MOD> a, unsigned long long k)
{
    modint<MOD> r = 1;
    while (k)
    {
        if (k & 1)
            r *= a;
        a *= a;
        k >>= 1;
    }
    return r;
}
typedef modint<1000000007> mint;

template <typename T, int MAX_>
struct Comb
{
    vector<T> fac, ifac;
    Comb()
    {
        fac.resize(MAX_, 1);
        ifac.resize(MAX_, 1);
        for (int i = 1; i <= MAX_; i++)
            fac[i] = fac[i - 1] * i;
        ifac[MAX_ - 1] = T(1) / fac[MAX_ - 1];
        for (int i = MAX_ - 2; i >= 1; i--)
            ifac[i] = ifac[i + 1] * T(i + 1);
    };
    T aPb(int a, int b)
    {
        if (b < 0 || a < b)
            return T(0);
        return fac[a] * ifac[a - b];
    }
    T aCb(int a, int b)
    {
        if (b < 0 || a < b)
            return T(0);
        return fac[a] * ifac[a - b] * ifac[b];
    }
    T nHk(int n, int k)
    {
        if (n == 0 && k == 0)
            return T(1);
        if (n <= 0 || k < 0)
            return 0;
        return aCb(n + k - 1, k);
    }
};
Comb<mint, 5000> com;

int main()
{
    cout << com.aCb(3, 1) << endl;
}
