#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int bit = 0; bit < (1 << n); bit++)
    {
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}