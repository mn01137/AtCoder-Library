#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 2, m = 5;
    int a[n][m] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};

    // 90度回転
    int ans1[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans1[i][j] = a[n - 1 - j][i];
        }
    }

    // 180度回転
    int ans2[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans2[i][j] = a[n - 1 - i][m - 1 - j];
        }
    }

    // 270度回転
    int ans3[n][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans3[i][j] = a[j][m - 1 - i];
        }
    }
}