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
#include <tuple>

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

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
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

#include <cstdio>

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
void solve()
{
    int n, q;
    cin >> n >> q;
    vi fa(n, -1);
    vvi h(n);
    for (int i = 1; i < n; i++)
    {
        cin >> fa[i];
        fa[i]--;
        h[fa[i]].pb(i);
    }

    vi nodeNum(n);

    auto dfs1 = [&](auto &&self, int u) -> int
    {
        nodeNum[u] = 1;
        for (auto v : h[u])
        {
            nodeNum[u] += self(self, v);
        }
        return nodeNum[u];
    };
    dfs1(dfs1, 0);

    vi p(n);
    vi pos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }

    int wrongNum = 0;
    vector<set<int>> son(n);

    auto add = [&](int i, int x)
    {
        son[i].insert(x);
        auto it = son[i].find(x);
        int l = -1, r = -1;
        if (it != son[i].begin())
        {
            l = *prev(it);
            if (l + nodeNum[p[l]] != x)
                wrongNum++;
        }
        if (next(it) != son[i].end())
        {
            r = *next(it);
            if (x + nodeNum[p[x]] != r)
                wrongNum++;
        }
        if (l != -1 && r != -1)
        {
            if (l + nodeNum[p[l]] != r)
                wrongNum--;
        }
    };

    for (int i = 0; i < n; i++)
    {
        if (fa[p[i]] != -1)
            add(fa[p[i]], i);
    }

    auto cal = [&](int i)
    {
        if (son[i].empty())
            return false;
        int x = pos[i];
        int y = *son[i].begin();
        return y < x;
    };

    for (int i = 0; i < n; i++)
    {
        wrongNum += cal(i);
    }

    auto remove = [&](int i, int x)
    {
        auto it = son[i].find(x);
        int l = -1, r = -1;
        if (it != son[i].begin())
        {
            l = *prev(it);
            if (l + nodeNum[p[l]] != x)
                wrongNum--;
        }
        if (next(it) != son[i].end())
        {
            r = *next(it);
            if (x + nodeNum[p[x]] != r)
                wrongNum--;
        }
        if (l != -1 && r != -1)
        {
            if (l + nodeNum[p[l]] != r)
                wrongNum++;
        }
        son[i].erase(it);
    };

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        set<int> change;
        change.insert(p[x]);
        change.insert(p[y]);
        change.insert(fa[p[x]]);
        change.insert(fa[p[y]]);

        for (auto x : change)
        {
            if (x != -1)
                wrongNum -= cal(x);
        }

        if (fa[p[x]] != -1)
            remove(fa[p[x]], x);
        if (fa[p[y]] != -1)
            remove(fa[p[y]], y);

        swap(p[x], p[y]);
        swap(pos[p[x]], pos[p[y]]);

        if (fa[p[x]] != -1)
            add(fa[p[x]], x);
        if (fa[p[y]] != -1)
            add(fa[p[y]], y);

        for (int x : change)
        {
            if (x != -1)
                wrongNum += cal(x);
        }

        if (!wrongNum)
            YES;
        else
            NO;
    }
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
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