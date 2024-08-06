#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <iomanip>
#include <random>

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
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define sort1_all(x) sort(x.begin() + 1, x.end())

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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, ll> psl;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pss> vpss;

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

template <typename T>
inline void read(T &x)
{
    T f = 1;
    x = 0;
    char ch = getchar();
    while (0 == isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (0 != isdigit(ch))
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        x = ~(x - 1);
        putchar('-');
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

/*#####################################BEGIN#####################################*/

const int N = 2e3 + 5;

int n, m, k;

int src;               // 源点
int h[N], e[N], ne[N]; // 邻接表存储所有边
int idx = 0;           // 记录当前边的编号
int w[N];              // 存储所有边的权值
int dist[N][N];        // 存储所有点到源点的距离
bitset<N> st;          // 存储每个点的最短距离是否已确定

void add(int a, int b, ll c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 求s点到n号点的最短距离，如果不存在，则返回-1
void dijkstra()
{
    dist[src][src] = 0;
    priority_queue<pii, vpii, greater<pii>> heap;
    heap.push({0, src}); // first存储距离，second存储节点编号

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;
        int distance = t.first;

        if (st[ver])
            continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[src][j] > distance + w[i])
            {
                dist[src][j] = distance + w[i];
                heap.push({dist[src][j], j});
            }
        }
    }
}

void solve()
{
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f, sizeof(dist));
    cin >> n >> m >> k;
    vpii edge;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
        edge.pb({a, b});
    }
    for (int i = 1; i <= n; i++)
    {
        src = i;
        st = 0;
        dijkstra();
    }
    vpii aim(k);
    for (int i = 0; i < k; i++)
    {
        cin >> aim[i].ft >> aim[i].sd;
    }
    int ans = inf;
    for (auto [u, v] : edge)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            int temp = min(dist[aim[j].ft][u] + dist[v][aim[j].sd], dist[aim[j].ft][v] + dist[u][aim[j].sd]);
            if (temp <= dist[aim[j].ft][aim[j].sd])
                sum += temp;
            else
                sum += dist[aim[j].ft][aim[j].sd];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
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