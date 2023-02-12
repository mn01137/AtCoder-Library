#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    do
    {
        for (auto s : v)
        {
            cout << s << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}