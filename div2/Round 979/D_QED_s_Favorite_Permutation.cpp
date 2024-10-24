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

struct seg
{
    int l, r;
    seg() : l(0), r(0) {}
    seg(int _l, int _r) : l(_l), r(_r) {}
    bool operator<(const seg &rhs) const
    {
        return l < rhs.l;
    }
};

template <typename T>
struct Fenwick
{
    int n;
    vector<T> a;

    Fenwick(int n_ = 0)
    {
        init(n_);
    }

    void init(int n_)
    {
        n = n_;
        a.assign(n + 1, T{});
    }

    void add(int x, const T &v)
    {
        for (int i = x; i <= n; i += i & -i)
        {
            a[i] = a[i] + v;
        }
    }

    T sum(int x)
    {
        T ans{};
        for (int i = x; i > 0; i -= i & -i)
        {
            ans = ans + a[i];
        }
        return ans;
    }

    T rangeSum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

struct node
{
    int a, b;
    node() : a(0), b(0) {}
    node(int _a, int _b) : a(_a), b(_b) {}
    bool operator<(const node &rhs) const
    {
        return a < rhs.a;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int mx = 0;
    int l = 1, r = 1;
    set<seg> st;
    for (int i = 1; i <= n; i++, r++)
    {
        mx = max(mx, a[i]);
        if (mx == r)
        {
            st.insert({l, r});
            l = i + 1;
        }
    }
    string s;
    cin >> s;
    s = " " + s;
    Fenwick<int> cntR(n + 1);
    Fenwick<int> cntL(n + 1);
    vector<node> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'R')
            cntR.add(i, 1), v[i].b = 0;
        else
            cntL.add(i, 1), v[i].b = 1;
        v[i].a = i;
    }
    ll sum = 0;
    for (auto it : st)
    {
        int l = it.l, r = it.r;
        for (int i = l; i <= r; i++)
        {
            if (s[i] == 'R')
                sum += cntL.rangeSum(l, i);
        }
    }

    while (q--)
    {
        int p;
        cin >> p;
        auto it = st.upper_bound({p, p});
        it = prev(it);
        int l = it->l, r = it->r;
        if (s[p] == 'R')
        {
            sum -= cntL.rangeSum(l, p);
            cntL.add(p, 1);
            cntR.add(p, -1);
            s[p] = 'L';
            sum += cntR.rangeSum(p, r);
        }
        else
        {
            sum -= cntR.rangeSum(p, r);
            cntL.add(p, -1);
            cntR.add(p, 1);
            s[p] = 'R';
            sum += cntL.rangeSum(l, p);
        }
        if (sum == 0)
            YES;
        else
            NO;
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