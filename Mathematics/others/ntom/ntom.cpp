#include <bits/stdc++.h>
using namespace std;

// 競プロ典型90問
// 067 - Base 8 to 9（★2）
// https://atcoder.jp/contests/typical90/tasks/typical90_bo

string ntom(const string str, const int n, const int m)
{
    unsigned long sum = 0;
    for (char c : str)
    {
        sum = sum * n + (c - '0');
    }
    string res = "";
    do
    {
        int num = sum % m;
        res = static_cast<char>(num + '0') + res;
        sum /= m;
    } while (sum);
    return res;
}

int main()
{
    string n;
    int k;
    cin >> n >> k;

    while (k--)
    {
        n = ntom(n, 8, 9);
        for (int i = 0; i < (int)n.size(); i++)
        {
            if (n[i] == '8')
            {
                n[i] = '5';
            }
        }
    }
    cout << n << endl;
}
