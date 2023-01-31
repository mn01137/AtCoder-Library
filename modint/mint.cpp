#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

template <int MOD>
struct ModInt
{
    static const int Mod = MOD;
    unsigned x;
    ModInt() : x(0) {}
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that)
    {
        if ((x += that.x) >= MOD)
            x -= MOD;
        return *this;
    }
    ModInt &operator-=(ModInt that)
    {
        if ((x += MOD - that.x) >= MOD)
            x -= MOD;
        return *this;
    }
    ModInt &operator*=(ModInt that)
    {
        x = (unsigned long long)x * that.x % MOD;
        return *this;
    }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const
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
        return ModInt(u);
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const
    {
        ModInt t;
        t.x = x == 0 ? 0 : Mod - x;
        return t;
    }
};
template <int MOD>
ostream &operator<<(ostream &st, const ModInt<MOD> a)
{
    st << a.get();
    return st;
};
template <int MOD>
ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k)
{
    ModInt<MOD> r = 1;
    while (k)
    {
        if (k & 1)
            r *= a;
        a *= a;
        k >>= 1;
    }
    return r;
}
typedef ModInt<1000000007> mint;

int main()
{
}