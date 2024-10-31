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
#define sort_all(x) sort(all(x))
#define sort1_all(x) sort(all1(x))

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

#define RED cout << "\033[91m"     // 红色
#define GREEN cout << "\033[92m"   // 绿色
#define YELLOW cout << "\033[93m"  // 蓝色
#define BLUE cout << "\033[94m"    // 品红
#define MAGENTA cout << "\033[95m" // 青色
#define CYAN cout << "\033[96m"    // 青色
#define RESET cout << "\033[0m"    // 重置

template <typename T>
void Debug(T x, int color = 1)
{
    switch (color)
    {
    case 1:
        RED;
        break;
    case 2:
        YELLOW;
        break;
    case 3:
        BLUE;
        break;
    case 4:
        MAGENTA;
        break;
    case 5:
        CYAN;
        break;
    default:
        break;
    }
    cout << x;
    RESET;
}

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

// Dinic算法求最大流
template <class T>
struct MaxFlow
{
    // 内部结构体，表示图中的一条边
    struct _Edge
    {
        int to;                                    // 边的终点
        T cap;                                     // 边的容量
        _Edge(int to, T cap) : to(to), cap(cap) {} // 边的构造函数
    };

    int n;                 // 图中节点的数量
    vector<_Edge> e;       // 存储所有边
    vector<vector<int>> g; // 邻接表，g[u]存储与节点u相连的所有边的索引
    vector<int> cur, h;    // 当前正在探索的边的指针和节点的高度（层次）

    // 默认构造函数
    MaxFlow() {}

    // 带节点数量的构造函数，初始化图
    MaxFlow(int n)
    {
        init(n);
    }

    // 初始化图的节点数量，并清空之前的边和邻接表
    void init(int n)
    {
        this->n = n;
        e.clear();        // 清空所有边
        g.assign(n, {});  // 初始化邻接表，给每个节点分配一个空的边列表
        cur.assign(n, 0); // 初始化当前边指针数组为0
        h.assign(n, 0);   // 初始化高度数组为0
    }

    // 广度优先搜索，用于构建层次图
    bool bfs(int s, int t)
    {
        h.assign(n, -1); // 将所有节点的高度初始化为-1，表示未访问
        queue<int> que;  // 创建一个队列用于BFS
        h[s] = 0;        // 源点的高度设为0
        que.push(s);     // 将源点入队

        while (!que.empty())
        {
            int u = que.front(); // 取出队头节点
            que.pop();
            for (int i : g[u]) // 遍历节点u的所有边
            {
                auto [v, c] = e[i];      // 获取边的终点v和剩余容量c
                if (c > 0 && h[v] == -1) // 如果边有剩余容量且v未被访问
                {
                    h[v] = h[u] + 1; // 更新v的高度，即层次
                    if (v == t)
                        return true; // 如果到达汇点，层次图已经构建完成
                    que.push(v);     // 将v入队，继续BFS
                }
            }
        }
        return false; // 如果无法到达汇点，返回false
    }

    // 深度优先搜索，用于在层次图中寻找增广路径并进行流量增广
    T dfs(int u, int t, T f)
    {
        if (u == t)
            return f;                                    // 到达汇点，返回当前增广的流量f
        T r = f;                                         // 剩余需要增广的流量
        for (int &i = cur[u]; i < int(g[u].size()); ++i) // 遍历节点u的所有边，从当前边指针开始
        {
            int j = g[u][i];               // 获取边的索引
            auto [v, c] = e[j];            // 获取边的终点v和剩余容量c
            if (c > 0 && h[v] == h[u] + 1) // 如果边有剩余容量且v在层次图中的高度是u的高度加1
            {
                T a = dfs(v, t, min(r, c)); // 递归地尝试增广流量，选择最小的流量
                if (a > 0)
                {
                    e[j].cap -= a;     // 减少正向边的剩余容量
                    e[j ^ 1].cap += a; // 增加反向边的剩余容量
                    r -= a;            // 减少需要增广的剩余流量
                    if (r == 0)
                        return f; // 如果已经没有剩余流量需要增广，返回
                }
            }
        }
        return f - r; // 返回实际增广的流量
    }

    // 向图中添加一条从u到v的边，并添加对应的反向边
    void addEdge(int u, int v, T c)
    {
        g[u].push_back(e.size()); // 将边的索引添加到u的邻接表中
        e.emplace_back(v, c);     // 添加正向边
        g[v].push_back(e.size()); // 将反向边的索引添加到v的邻接表中
        e.emplace_back(u, 0);     // 添加反向边，初始容量为0
    }

    // 计算从源点s到汇点t的最大流
    T flow(int s, int t)
    {
        T ans = 0;        // 初始化最大流量为0
        while (bfs(s, t)) // 当存在从s到t的增广路径时
        {
            // 在每次BFS后需要重置当前边指针
            // 这是为了防止在DFS过程中重复遍历已经尝试过的边
            cur.assign(n, 0);
            // 尝试通过DFS增广流量，添加到总流量中
            ans += dfs(s, t, numeric_limits<T>::max());
        }
        return ans; // 返回最终的最大流量
    }

    // 计算最小割，返回一个布尔数组，表示每个节点是否在割集的一侧
    vector<bool> minCut()
    {
        vector<bool> c(n);
        for (int i = 0; i < n; i++)
            c[i] = (h[i] != -1); // 如果节点i的高度不为-1，表示可达源点侧
        return c;                // 返回最小割结果
    }

    // 定义一个边结构体，用于存储边的详细信息
    struct Edge
    {
        int from; // 边的起点
        int to;   // 边的终点
        T cap;    // 边的容量
        T flow;   // 边的流量
    };

    // 获取所有的边信息
    vector<Edge> edges()
    {
        vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) // 遍历所有正向边
        {
            Edge x;
            x.from = e[i + 1].to;            // 反向边的终点作为起点
            x.to = e[i].to;                  // 正向边的终点
            x.cap = e[i].cap + e[i + 1].cap; // 总容量为正向边和反向边的容量之和
            x.flow = e[i + 1].cap;           // 流量等于反向边的容量
            a.push_back(x);                  // 将边添加到结果集中
        }
        return a; // 返回所有边的信息
    }
};
void solve()
{
    ll n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // 创建一个最大流图，节点总数为n个元素节点 + 60个比特位节点 + 源点和汇点
    MaxFlow<int> graph(n + 62);
    int s = n + 60; // 定义源点的编号为n + 60
    int t = s + 1;  // 定义汇点的编号为s + 1

    // 为每个元素节点添加边连接到源点，容量为1，表示每个元素最多被选中一次
    for (int i = 0; i < n; i++)
    {
        graph.addEdge(s, i, 1);
        for (int j = 0; j < 60; j++) // 遍历每个比特位
        {
            if (a[i] >> j & 1)                // 如果元素a[i]的第j位为1
                graph.addEdge(i, n + j, inf); // 从元素节点i到比特位节点(n + j)添加无限容量的边
        }
    }

    // 为每个比特位节点添加边连接到汇点，容量为1，表示每个位只能被一个元素覆盖
    for (int j = 0; j < 60; j++)
    {
        graph.addEdge(n + j, t, 1);
    }

    // 计算最大流，即可以覆盖的比特位的最大数量
    int max_flow = graph.flow(s, t);
    // 根据题意，最大子序列的值为n - 被覆盖的比特位数量
    int ans = n - max_flow;
    cout << ans << "\n"; // 输出答案
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