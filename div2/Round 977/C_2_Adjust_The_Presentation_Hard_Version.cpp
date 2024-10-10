#define _CRT_SECURE_NO_WARNINGS 1

#include <algorithm>
#include <array>
#include <bitset>
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

const string t1 = "YA";
const string t2 = "TIDAK";

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vi a(n + 1);
    vi pos_a(n + 1, 0); // pos_a[x] 存储成员x在队伍中的位置
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pos_a[a[i]] = i;
    }

    vi b(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
    }

    // occ[x] 存储成员x在b数组中出现的所有幻灯片位置（有序）
    vector<set<int>> occ(n + 1, set<int>());
    for (int i = 1; i <= m; ++i)
    {
        occ[b[i]].insert(i);
    }

    // f[x] 存储成员x在b数组中第一次出现的位置，如果x不出现，则设为m+1
    vi f(n + 1, m + 1);
    for (int x = 1; x <= n; ++x)
    {
        if (!occ[x].empty())
            f[x] = *occ[x].begin();
    }

    // bad[i] 表示成员a[i]和a[i+1]的展示顺序是否不合法（即f[a[i]] > f[a[i+1]])
    vector<bool> bad(n, false);
    // 记录不合法的成员对数量
    int cnt = 0;
    for (int i = 1; i < n; ++i)
    {
        if (f[a[i]] > f[a[i + 1]])
        {
            bad[i] = true; // 标记第i对成员顺序不合法
            cnt++;         // 不合法对数量加1
        }
    }

    if (cnt == 0)
        cout << t1 << "\n"; // 如果没有不合法对，输出"YA"
    else
        cout << t2 << "\n"; // 否则，输出"TIDAK"

    while (q--)
    {
        int s, t;
        cin >> s >> t;

        int las = b[s]; // 记录更新前第s张幻灯片展示的成员las
        int nex = t;    // 更新后要展示的成员nex

        if (las == nex)
        {
            // 如果更新前后成员相同，展示顺序不变
            if (cnt == 0)
                cout << t1 << "\n";
            else
                cout << t2 << "\n";
            continue;
        }

        // 从成员las的出现集合中移除位置s
        occ[las].erase(s);
        if (!occ[las].empty())
            f[las] = *occ[las].begin(); // 更新成员las的第一次出现位置
        else
            f[las] = m + 1; // 如果成员las不再出现在b中，设为m+1

        // 将位置s加入成员nex的出现集合
        occ[nex].insert(s);
        if (s < f[nex])
            f[nex] = s; // 如果s小于当前成员nex的第一次出现位置，更新f[nex]
        b[s] = nex;     // 更新b数组中第s张幻灯片展示的成员为nex

        // 获取成员las和nex在初始排列中的位置
        int pos_las = pos_a[las];
        int pos_nex = pos_a[nex];

        // temp集合存储需要检查的相邻成员对的位置
        set<int> temp;
        if (pos_las > 1)
            temp.insert(pos_las - 1); // 检查pos_las-1和pos_las的成员对
        if (pos_las < n)
            temp.insert(pos_las); // 检查pos_las和pos_las+1的成员对
        if (pos_nex > 1)
            temp.insert(pos_nex - 1); // 检查pos_nex-1和pos_nex的成员对
        if (pos_nex < n)
            temp.insert(pos_nex); // 检查pos_nex和pos_nex+1的成员对

        // 遍历所有需要检查的相邻成员对，更新不合法对的计数
        for (auto idx : temp)
        {
            int u = a[idx];            // 成员u在位置idx
            int v = a[idx + 1];        // 成员v在位置idx+1
            bool was_bad = bad[idx];   // 记录之前是否不合法
            bool is_bad = f[u] > f[v]; // 计算当前是否不合法

            if (was_bad != is_bad)
            {
                if (is_bad)
                    cnt++; // 如果现在变为不合法，对数加1
                else
                    cnt--;         // 如果现在变为合法，对数减1
                bad[idx] = is_bad; // 更新bad数组中的状态
            }
        }

        // 根据更新后的不合法对数量，输出结果
        if (cnt == 0)
            cout << t1 << "\n";
        else
            cout << t2 << "\n";
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