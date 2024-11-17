#include <bits/stdc++.h>

using namespace std;

#define ft first
#define sd second

#define yes cout << "yes\n"
#define no cout << "no\n"

#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define pb push_back
#define eb emplace_back

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define unq_all1(x) x.erase(unique(all1(x)), x.end())
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

#define RED cout << "\033[91m"     // 红色
#define GREEN cout << "\033[92m"   // 绿色
#define YELLOW cout << "\033[93m"  // 蓝色
#define BLUE cout << "\033[94m"    // 品红
#define MAGENTA cout << "\033[95m" // 青色
#define CYAN cout << "\033[96m"    // 青色
#define RESET cout << "\033[0m"    // 重置

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t i128;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<string, ll> psl;

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
inline T read()
{
    T x = 0;
    int y = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            y = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * y;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x >= 10)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

/*#####################################BEGIN#####################################*/
template <typename T>
struct Fenwick
{
    int n;       // 数组大小
    vector<T> a; // 存储树状数组的数组

    // 构造函数，初始化树状数组
    Fenwick(int n_ = 0)
    {
        init(n_);
    }

    // 初始化树状数组
    void init(int n_)
    {
        n = n_;               // 设置大小
        a.assign(n + 1, T{}); // 初始化数组，所有元素为0
    }

    // 在索引 x 上添加值 v
    void add(int x, const T &v)
    {
        for (int i = x; i <= n; i += i & -i)
        {                        // 从 x 开始更新
            a[i] = max(a[i], v); // 更新当前节点
        }
    }

    // 计算前缀和，从 0 到 x
    T query(int x)
    {
        T ans{}; // 初始化结果为 0
        for (int i = x; i > 0; i -= i & -i)
        {                         // 从 x 向上遍历
            ans = max(ans, a[i]); // 累加当前节点的值
        }
        return ans; // 返回前缀和
    }
};
void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    Fenwick<int> fen(n);
    vi pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = max(pre[i - 1], a[i]);
    }
    vi ans(n + 1);
    for (int i = n; i >= 1; i--)
    {
        ans[i] = max(pre[i], fen.query(pre[i] - 1));
        fen.add(a[i], ans[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：