#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

const int INF = INT_MAX;
const long long LINF = 1e18;
const long long MOD1000000007 = 1000000007;
const long long MOD998244353 = 998244353;

using namespace std;

/*
  　　∧_∧
　（ ´・ω・)
　 //＼￣￣旦＼   @author mn01137
／/ ※ ＼＿＿＿＼
＼＼ 　※ 　※ 　※ ヽ
　 ＼ヽ-＿_＿--＿__ヽ
*/

/*---------------- typedef ----------------------*/

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*---------------- function ----------------------*/
template <class T>
bool clamp(T x, T min, T max) { return (x >= min and x <= max); }
void YesNo(bool ok) { cout << (ok ? "Yes" : "No") << endl; }
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
template <class T>
T apsum(T n, T a1, T d) { return (n * (2 * a1 + (n - 1) * d)) / 2; }

/*-------------- input stream ------------------*/
#ifdef __LOCAL
static istream *inputStream = &cin;
void inputTestCaseInLocal(string path)
{
    size_t pos = path.find_last_of("\\/");
    string fileName = (pos == string::npos ? path : path.substr(pos + 1));
    pos = fileName.find_last_of(".");
    if (pos != string::npos)
        fileName = fileName.substr(0, pos);
    static ifstream file("input/" + fileName + ".txt");
    if (file and file.peek() != ifstream::traits_type::eof())
        inputStream = &file;
}
void INPUT() {}
template <typename Head, typename... Tail>
void INPUT(Head &&head, Tail &&...tail)
{
    (*inputStream) >> head;
    INPUT(forward<Tail>(tail)...);
}
template <typename T, typename... Vectors>
void INPUT(std::vector<T> &first, std::vector<Vectors> &...rest)
{
    size_t size = first.size();
    for (size_t i = 0; i < size; ++i)
    {
        (*inputStream) >> first[i];
        (void)std::initializer_list<int>{((*inputStream) >> rest[i], 0)...};
    }
}
#else
void inputTestCaseInLocal([[maybe_unused]] string path) {}
void INPUT() {}
template <typename Head, typename... Tail>
void INPUT([[maybe_unused]] Head &&head, [[maybe_unused]] Tail &&...tail)
{
    cin >> head;
    INPUT(forward<Tail>(tail)...);
}
template <typename T, typename... Vectors>
void INPUT([[maybe_unused]] vector<T> &first, [[maybe_unused]] vector<Vectors> &...rest)
{
    size_t size = first.size();
    for (size_t i = 0; i < size; ++i)
    {
        cin >> first[i];
        (void)std::initializer_list<int>{(cin >> rest[i], 0)...};
    }
}
#endif

/*---------------- debug ---------------------*/

#ifdef __LOCAL
void views() { cout << endl; }
template <class Head, class... Tail>
void views([[maybe_unused]] Head &&head, [[maybe_unused]] Tail &&...tail)
{
    cout << head << " ";
    views(move(tail)...);
}
template <typename T>
void view(const std::vector<T> &v)
{
    for (const auto &e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}
template <typename T>
void view(const vector<std::vector<T>> &vv)
{
    for (const auto &v : vv)
    {
        view(v);
    }
}
#else
template <class Head, class... Tail>
void view([[maybe_unused]] Head &&head, [[maybe_unused]] Tail &&...tail) {}
template <typename T>
void view([[maybe_unused]] T e) {}
template <typename T>
void view([[maybe_unused]] const vector<T> &v) {}
template <typename T>
void view([[maybe_unused]] const vector<vector<T>> &vv) {}
#endif

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
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    // cout << fixed << setprecision(10);
    cin.tie(0)->sync_with_stdio(0);
    inputTestCaseInLocal(argv[0]);
    int t = 1;
    while (t--)
    {
        solve();
        // solve2();
    }

    return 0;
}
