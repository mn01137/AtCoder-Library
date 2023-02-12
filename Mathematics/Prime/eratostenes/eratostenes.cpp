#include <bits/stdc++.h>
using namespace std;

vector<bool> eratostenes(int n)
{
    vector<bool> isprime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = 2; i * j <= n; j++)
            {
                isprime[i * j] = false;
            }
        }
    }
    return isprime;
}

int main()
{
    int n;
    cin >> n;
    const auto &isprime = eratostenes(n);
    if (isprime[n])
    {
        cout << "prime" << endl;
    }
    else
    {
        cout << "not prime" << endl;
    }
}