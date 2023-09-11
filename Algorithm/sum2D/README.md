# 2次元累積和
前計算： O ($n^2$)<br>
累積和計算： O ($1$)
```
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
```
