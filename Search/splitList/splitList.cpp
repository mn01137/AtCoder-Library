#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8;
    int s = 62;
    vector<int> num = {31, 15, 11, 20, 13, 8, 5, 9};

    // 前半をbit全探索で全列挙
    vector<int> A;
    for (int bit = 0; bit < (1 << n / 2); bit++)
    {
        int sum = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (bit & (1 << i))
            {
                sum += num[i];
            }
        }
        A.push_back(sum);
    }
    // 後半をbit全探索で全列挙
    vector<int> B;
    for (int bit = 0; bit < (1 << (n - n / 2)); bit++)
    {
        int sum = 0;
        for (int i = 0; i < (n - n / 2); i++)
        {
            if (bit & (1 << i))
            {
                sum += num[n / 2 + i];
            }
        }
        B.push_back(sum);
    }
    sort(B.begin(), B.end());
    // Aを固定して二分探索
    int ans = 0;
    for (auto a : A)
    {
        if (s - a >= 0)
        {
            ans = max(ans, a + *(upper_bound(B.begin(), B.end(), s - a) - 1));
        }
    }
    // ans = 62
    cout << ans << endl;
}