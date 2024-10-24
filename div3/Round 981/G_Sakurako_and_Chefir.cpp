#define _CRT_SECURE_NO_WARNINGS 1

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

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
#define sort_all(x) sort(all(x))
#define sort1_all(x) sort(all1(x))
#define reverse_all(x) reverse(all(x))
#define reverse1_all(x) reverse(all1(x))

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"

// 红色
#define DEBUG1(x)                     \
    RED;                              \
    cout << #x << " : " << x << endl; \
    RESET;

// 绿色
#define DEBUG2(x)                     \
    GREEN;                            \
    cout << #x << " : " << x << endl; \
    RESET;

// 蓝色
#define DEBUG3(x)                     \
    BLUE;                             \
    cout << #x << " : " << x << endl; \
    RESET;

// 品红
#define DEBUG4(x)                     \
    MAGENTA;                          \
    cout << #x << " : " << x << endl; \
    RESET;

// 青色
#define DEBUG5(x)                     \
    CYAN;                             \
    cout << #x << " : " << x << endl; \
    RESET;

// 黄色
#define DEBUG6(x)                     \
    YELLOW;                           \
    cout << #x << " : " << x << endl; \
    RESET;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t i128;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef pair<ll, int> pli;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, ll> psl;

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pli> vpli;
typedef vector<pss> vpss;
typedef vector<ti3> vti3;
typedef vector<tl3> vtl3;
typedef vector<tld3> vtld3;

typedef vector<vi> vvi;
typedef vector<vl> vvl;

typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<pii> qpii;
typedef queue<pll> qpll;
typedef queue<psi> qpsi;
typedef queue<psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pll> pqpll;
typedef priority_queue<psi> pqpsl;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<ll, ll> mll;
typedef map<ll, bool> mlb;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<char, bool> mcb;
typedef map<string, int> msi;
typedef map<string, ll> msl;
typedef map<int, bool> mib;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

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

// 懒标记线段树模板类
template <class Info, class Tag>
struct LazySegmentTree
{
    const int n;            // 数组大小
    std::vector<Info> info; // 存储线段树节点的信息
    std::vector<Tag> tag;   // 存储懒标记

    // 构造函数
    LazySegmentTree(int n) : n(n), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}

    // 用于初始化线段树的构造函数
    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size())
    {
        std::function<void(int, int, int)> build = [&](int p, int l, int r)
        {
            if (r - l == 1)
            {
                info[p] = init[l]; // 叶子节点赋值
                return;
            }
            int m = (l + r) / 2;    // 中间点
            build(2 * p, l, m);     // 构建左子树
            build(2 * p + 1, m, r); // 构建右子树
            pull(p);                // 更新父节点
        };
        build(1, 0, n);
    }

    // 更新父节点
    void pull(int p)
    {
        info[p] = info[2 * p] + info[2 * p + 1]; // 合并左右子树的信息
    }

    // 应用标签到节点
    void apply(int p, const Tag &v)
    {
        info[p].apply(v); // 应用标签到信息
        tag[p].apply(v);  // 更新懒标记
    }

    // 推送懒标记到子节点
    void push(int p)
    {
        apply(2 * p, tag[p]);     // 推送到左子树
        apply(2 * p + 1, tag[p]); // 推送到右子树
        tag[p] = Tag();           // 清空当前节点的懒标记
    }

    // 修改某个位置的值
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v; // 更新叶子节点
            return;
        }
        int m = (l + r) / 2; // 中间点
        push(p);             // 推送懒标记
        if (x < m)
        {
            modify(2 * p, l, m, x, v); // 递归到左子树
        }
        else
        {
            modify(2 * p + 1, m, r, x, v); // 递归到右子树
        }
        pull(p); // 更新父节点
    }

    // 对外接口，修改某个位置的值
    void modify(int p, const Info &v)
    {
        modify(1, 0, n, p, v);
    }

    // 区间查询
    Info rangeQuery(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
        {
            return Info(); // 范围不相交，返回默认信息
        }
        if (l >= x && r <= y)
        {
            return info[p]; // 当前区间完全包含在查询范围内
        }
        int m = (l + r) / 2; // 中间点
        push(p);             // 推送懒标记
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }

    // 对外接口，区间查询
    Info rangeQuery(int l, int r)
    {
        return rangeQuery(1, 0, n, l, r);
    }
};

// 标签结构
struct Tag
{
    int change = -inf; // 增加的值

    // 应用标签的操作
    void apply(Tag t) &
    {
        change = t.change; // 累加增加的值
    }
};

// 信息结构
struct Info
{
    int max = -inf;
    void apply(Tag t) &
    {
        if (t.change != -inf)
        {
            max = t.change; // 更新最大值
        }
    }

    Info() {};
    Info(int x) : max(x) {}
};

// 信息结构的加法运算符重载
Info operator+(Info a, Info b)
{
    Info c;
    c.max = max(a.max, b.max);
    return c;
}

// 查询结构体
struct Query
{
    int k;
    int id;
    Query(int k_, int id_) : k(k_), id(id_) {}
};

void solve()
{
    int n;
    cin >> n;
    vvi adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi dep(n + 1);    // 存储每个节点的深度
    vi maxDep(n + 1); // 存储每个节点可以向下走的最大深度

    // 深度优先搜索 (DFS) 函数，用于计算每个节点的深度和最大深度
    function<void(int, int)> dfs1 = [&](int u, int fa)
    {
        maxDep[u] = 0;
        for (auto v : adj[u])
        {
            if (v == fa) // 如果 v 是父节点，跳过
                continue;
            dep[v] = dep[u] + 1;
            dfs1(v, u);
            maxDep[u] = max(maxDep[u], maxDep[v] + 1);
        }
    };
    dfs1(1, 0);

    int m;
    cin >> m;
    vector<vector<Query>> querys(n + 1);
    vi ans(m);

    for (int i = 0; i < m; i++)
    {
        int v, k;
        cin >> v >> k;
        querys[v].pb({k, i});
    }

    // 创建线段树
    LazySegmentTree<Info, Tag> seg(n);

    // 处理查询
    function<void(int, int)> dfs2 = [&](int u, int fa)
    {
        // 处理当前节点 u 的所有查询
        for (auto &q : querys[u])
        {
            int k = q.k, id = q.id;
            ans[id] = max(ans[id], maxDep[u]); // 更新答案为当前节点的最大深度
            // 通过线段树查询从 可到达最浅深度dep[u] - k 到 dep[u] 的最大值，并加上 dep[u]
            ans[id] = max(ans[id], seg.rangeQuery(max(0, dep[u] - k), dep[u]).max + dep[u]);
        }

        // 找到当前节点 u 的子节点中最大和次大子树深度
        int max1 = 0, max2 = 0;
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            if (maxDep[v] + 1 > max1)
            {
                max2 = max1;
                max1 = maxDep[v] + 1;
            }
            else if (maxDep[v] + 1 > max2)
            {
                max2 = maxDep[v] + 1;
            }
        }

        // 递归处理每个子节点
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            // 如果当前子节点的最大深度 + 1 等于 max1,说明最大子树深度就是maxDep[v]，不能重复选，选次大子树深度
            int d = maxDep[v] + 1 == max1 ? max2 : max1;
            seg.modify(dep[u], Info(d - dep[u])); // 在线段树中添加走到u节点可向下走的最大深度
            dfs2(v, u);
            seg.modify(dep[u], -inf); // 回溯时重置线段树中的值
        }
    };
    dfs2(1, 0);
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << " \n"[i == m - 1];
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