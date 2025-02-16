#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

vector<array<long long, 3>> queries;
vector<long long> answer;

int LIS(const vector<long long> &A)
{
    int N = (int)A.size();
    long long LIS_INF = 1LL << 60;
    vector<long long> dp(N, LIS_INF);
    int query_cnt = 0;
    for (int i = 0; i < N; i++)
    {
        // dp[k] >= A[i]となる最小のイテレータ
        auto itr = lower_bound(dp.begin(), dp.end(), A[i]);

        // そこをA[i]でおきかえる
        // dp[k] : 最長部分増加列の長さがkのときの，i番目まで見た場合の一番後ろの数
        *itr = A[i];

        // ABC393 F
        // 置き換えた後，iの長さがクエリのRと一致している場合，dp[k] <=　Xとなる最大のkを
        // 二分探索で求めに行く
        while (query_cnt < (int)queries.size())
        {
            long long R = queries[query_cnt][0];
            long long X = queries[query_cnt][1];
            long long index_num = queries[query_cnt][2];

            // iがRと一致しているか？
            if (R - 1 == i)
            {
                // dp[k] <= X となる最大のkを求める
                int k = upper_bound(dp.begin(), dp.end(), X) - dp.begin();
                answer[index_num] = k;
                query_cnt++;
            }
            else
            {
                // していない場合は次回以降．
                break;
            }
        }
    }

    // dp[k] < INFとなる最大のkに対して，長さk+1がLISの答え
    // 問題に合わせて調整する．
    return lower_bound(dp.begin(), dp.end(), LIS_INF) - dp.begin();
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    queries.resize(Q);
    answer.resize(Q);
    for (int i = 0; i < Q; i++)
    {
        long long R, X;
        cin >> R >> X;
        queries[i] = {R, X, i};
    }

    // Rが小さい順にクエリを並び替え
    sort(queries.begin(), queries.end(), [&](auto a, auto b)
         { return a[0] < b[0]; });

    LIS(A);

    for (int i = 0; i < Q; i++)
    {
        cout << answer[i] << "\n";
    }
}
