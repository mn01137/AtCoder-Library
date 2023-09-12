#include <bits/stdc++.h>

const int INF = INT_MAX;
const long long LINF = 1e18;
const long long MOD17 = 1000000007;
const long long MOD99 = 998244353;

using namespace std;

/*
  　　∧_∧
　（ ´・ω・)
　 //＼￣￣旦＼   @author mn01137
／/ ※ ＼＿＿＿＼
＼＼ 　※ 　※ 　※ ヽ
　 ＼ヽ-＿_＿--＿__ヽ
*/

/*---------------- typedef  ----------------------*/

typedef long long ll;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*---------------- function  -------------------------*/

template <class T>
bool clamp(T x, T min, T max) { return (x >= min and x <= max); }
template <class T>
void chmin(T &a, const T &b)
{
    if (b < a)
        a = b;
}
template <class T>
void chmax(T &a, const T &b)
{
    if (a < b)
        a = b;
}
template <class T>
T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b)
{
    return a / gcd(a, b) * b;
}
/**
 * @brief arithmetic progression sum
 *
 * @tparam T
 * @param n number of terms
 * @param a1 first terms
 * @param d difference
 * @return T
 */
template <class T>
T apsum(T n, T a1, T d) { return (n * (2 * a1 + (n - 1) * d)) / 2; }

/*---------------- debug  ---------------------*/

template <class T>
void print(vector<T> &a)
{
    for (auto nx : a)
        cout << nx << ' ';
    cout << endl;
}
template <class T>
void print(vector<vector<T>> &a)
{
    for (auto nv : a)
    {
        for (auto nx : nv)
            cout << nv << ' ';
        cout << endl;
    }
}
template <class T>
void print(set<T> &a)
{
    for (auto nx : a)
        cout << nx << ' ';
    cout << endl;
}
template <class T>
void print(multiset<T> &a)
{
    for (auto nx : a)
        cout << nx << ' ';
    cout << endl;
}

/*---------------- macro -------------------------*/

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, j, n) for (int i = j; i < (int)(n); i++)
#define revrep(i, n) for (int i = n; i >= 0; i--)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep1(i, j, n) for (int i = j; i <= (int)(n); i++)
#define each(i, a) for (auto &&i : a)
#define bit(k) (1LL << (k))
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset(x, y, sizeof(x))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define SZ(a) int((a).size())

/*-------------- source code --------------------*/

// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};

void solve2()
{
}

void solve()
{
    cout << apsum(10, 1, 2) << endl;
}

int main()
{
    // cout << fixed << setprecision(10);
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // solve2();

    return 0;
}
