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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<array<int, 2>>> adj1(n);
    int m1;
    cin >> m1;
    for (int i = 0; i < m1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj1[u].pb({v, 1});
        adj1[v].pb({u, k - 1});
    }
    vi b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<vector<array<int, 2>>> adj2(n);
    int m2;
    cin >> m2;
    for (int i = 0; i < m2; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj2[u].pb({v, 1});
        adj2[v].pb({u, k - 1});
    }

    vi fa(n, -1), fb(n, -1);
    qi q;
    q.push(0);
    fa[0] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj1[u])
        {
            if (fa[v] == -1)
            {
                fa[v] = (fa[u] + w) % k;
                q.push(v);
            }
        }
    }
    q.push(0);
    fb[0] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj2[u])
        {
            if (fb[v] == -1)
            {
                fb[v] = (fb[u] + w) % k;
                q.push(v);
            }
        }
    }

    int a0 = count(a.begin(), a.end(), 0);
    int b1 = count(b.begin(), b.end(), 1);
    if (a0 != b1)
    {
        NO;
        return;
    }
    if (a0 == 0 || a0 == n)
    {
        YES;
        return;
    }
    vl s(k), t(k);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            fa[i] = (fa[i] + 1) % k;
            s[fa[i]] += n;
        }
        else
        {
            fa[i] = (fa[i] - 1 + k) % k;
            s[fa[i]] += 1;
        }
        if (b[i] == 0)
        {
            t[fb[i]] += n;
        }
        else
        {
            t[fb[i]] += 1;
        }
    }
    s.pb(-1);
    s.insert(s.end(), t.begin(), t.end());
    s.insert(s.end(), t.begin(), t.end());
    vi f(s.size() + 1);
    for (int i = 1, j = 0; i < s.size(); i++)
    {
        while (j && s[i] != s[j])
        {
            j = f[j];
        }
        j += (s[i] == s[j]);
        if (j == k)
        {
            YES;
            return;
        }
        f[i + 1] = j;
    }
    NO;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：