#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = n; i >= 0; i--)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define bit(k) (1LL << (k))
#define all(x) (x).begin(), (x).end()

template <typename T>
struct Sum2D
{
private:
    vector<vector<T>> sum;

public:
    int H, W;
    vector<vector<T>> n;
    Sum2D(int H_, int W_) : H(H_), W(W_)
    {
        n.assign(H, vector<T>(W, 0));
        sum.assign(H + 1, vector<T>(W + 1, 0));
    }
    Sum2D() {}
    void PrefixSum2D()
    {
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + n[i][j];
            }
        }
    }
    // [sx,sy) x [gx,gy)
    T Sum(int sx, int sy, int gx, int gy)
    {
        return sum[gx][gy] - sum[sx][gy] - sum[gx][sy] + sum[sx][sy];
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> g = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    Sum2D<int> sum2d(n, n);
    sum2d.n = g;
    // 前計算 O(n^2)
    sum2d.PrefixSum2D();
    // 導出 O(1)
    cout << sum2d.Sum(1, 1, 3, 3) << endl; // 10
}
