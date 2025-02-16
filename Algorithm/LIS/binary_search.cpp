#include <bits/stdc++.h>
using namespace std;

int LIS(const vector<long long> &A)
{
    int N = (int)A.size();
    long long LIS_INF = 1LL << 60;
    vector<long long> dp(N, LIS_INF);
    for (int i = 0; i < N; i++)
    {
        // dp[k] >= A[i]となる最小のイテレータ
        auto itr = lower_bound(dp.begin(), dp.end(), A[i]);

        // そこをA[i]でおきかえる
        // dp[k] : 最長部分増加列の長さがkのときの，i番目まで見た場合の一番後ろの数
        *itr = A[i];
    }

    // dp[k] < INFとなる最大のkに対して，長さk+1がLISの答え
    // 問題に合わせて調整する．
    return lower_bound(dp.begin(), dp.end(), LIS_INF) - dp.begin();
}

int main()
{
    int n = 7;
    vector<long long> A = {0, 2, 3, 6, 5, 12, 15};
    cout << LIS(A) << endl;
}
