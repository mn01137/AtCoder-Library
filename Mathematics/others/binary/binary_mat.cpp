#include <bits/stdc++.h>
using namespace std;

template <class T>
vector<vector<T>> mat_mul(vector<vector<T>> a, vector<vector<T>> b)
{
    int n = a.size();
    vector<vector<T>> res(n, vector<T>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] = a[i][k] * b[k][j];
            }
        }
    }
}

template <class T>
vector<vector<T>> mat_pow(vector<vector<T>> a, T b)
{
    int n = a.size();
    vector<vector<T>> res(n, vector<T>(n, 0));
    for (int i = 0; i < n; i++)
    {
        res[i][i] = 1;
    }
    while (b)
    {
        if (b & 1)
        {
            res = mat_mul(res, a);
        }
        a = mat_mul(a, a);
        b >>= 1;
    }
    return res;
}

template <class T>
vector<vector<T>> mat_mul_mod(vector<vector<T>> a, vector<vector<T>> b, T mod)
{
    int n = a.size();
    vector<vector<T>> res(n, vector<T>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] = a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
}

template <class T>
vector<vector<T>> mat_pow_mod(vector<vector<T>> a, T b, T mod)
{
    int n = a.size();
    vector<vector<T>> res(n, vector<T>(n, 0));
    for (int i = 0; i < n; i++)
    {
        res[i][i] = 1;
    }
    while (b)
    {
        if (b & 1)
        {
            res = mat_mul_mod(res, a, mod);
        }
        a = mat_mul_mod(a, a, mod);
        b >>= 1;
    }
    return res;
}

int main()
{
}