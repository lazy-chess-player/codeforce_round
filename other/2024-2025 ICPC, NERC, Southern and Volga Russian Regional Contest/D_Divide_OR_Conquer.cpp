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

namespace SegTree
{
#define ls rt << 1          // 定义宏ls，表示当前节点的左子节点编号。
#define rs rt << 1 | 1      // 定义宏rs，表示当前节点的右子节点编号。
#define lson ls, l, mid     // 定义宏lson，表示递归处理左子树的参数。
#define rson rs, mid + 1, r // 定义宏rson，表示递归处理右子树的参数。

    const int N = 2e5 + 5;
    struct Info
    {
        int val;
        Info(int v_ = 0) : val(v_) {}
        friend Info operator+(const Info &a, const Info &b)
        {
            return {a.val | b.val};
        }
    } tr[N << 2]; // 线段树数组，大小为4倍的N，用于存储所有节点信息。

    Info a[N];
    // pushUp函数用于在递归构建或更新线段树时，向上更新当前节点的信息。
    void pushUp(int rt) { tr[rt] = tr[ls] + tr[rs]; }

    void build(int rt, int l, int r)
    {
        if (l == r) // 如果当前区间长度为1，即叶子节点。
        {
            tr[rt] = a[l];
            return;
        }
        int mid = l + r >> 1; // 计算当前区间的中点。
        build(lson);          // 递归构建左子树。
        build(rson);          // 递归构建右子树。
        pushUp(rt);           // 向上更新当前节点的信息。
    }

    Info query(int rt, int l, int r, int L, int R)
    {
        if (l >= L && r <= R) // 如果当前节点的区间完全被查询区间覆盖，直接返回当前节点信息。
            return tr[rt];
        int mid = l + r >> 1; // 计算当前区间的中点。
        if (mid >= R)         // 如果查询区间完全位于左子树，递归查询左子树。
            return query(lson, L, R);
        if (mid < L) // 如果查询区间完全位于右子树，递归查询右子树。
            return query(rson, L, R);
        // 如果查询区间跨越左右子树，分别查询左右子树的信息并合并。
        return query(lson, L, R) + query(rson, L, R);
    }
}

// 引入SegTree命名空间中的build和query函数，方便直接调用。
using namespace SegTree;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].val;
    }
    build(1, 1, n);
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    // std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：