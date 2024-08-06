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

#define endl '\n'

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

#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffffLL

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
typedef priority_queue<pll> pqpl;
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

void solve()
{
    int n;
    cin >> n;
    vl a(n + 1);
    vl b(n + 1);
    vl c(n + 1);
    vvl pre(3, vl(n + 1));
    vvl suf(3, vl(n + 1));
    ll tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tot += a[i];
        pre[0][i] = pre[0][i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        pre[1][i] = pre[1][i - 1] + b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        pre[2][i] = pre[2][i - 1] + c[i];
    }
    ll aim = (tot + 2) / 3;
    vi rp(3);
    vi lp(3);
    for (int i = 1; i <= n; i++)
    {
        if (rp[0] == 0 && pre[0][i] >= aim)
            rp[0] = i;
        if (rp[1] == 0 && pre[1][i] >= aim)
            rp[1] = i;
        if (rp[2] == 0 && pre[2][i] >= aim)
            rp[2] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        if (lp[0] == 0 && tot - pre[0][i] >= aim)
            lp[0] = i + 1;
        if (lp[1] == 0 && tot - pre[1][i] >= aim)
            lp[1] = i + 1;
        if (lp[2] == 0 && tot - pre[2][i] >= aim)
            lp[2] = i + 1;
    }
    // cout << "----------" << endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << rp[i] << " " << lp[i] << " " << endl;
    // }
    // cout << "----------" << endl;
    for (int i = 0; i < 3; i++)
    {
        if (rp[i] == n - 1)
            continue;
        for (int j = 0; j < 3; j++)
        {
            if (j == i)
                continue;
            if (lp[j] == 2)
                continue;
            if (lp[j] <= rp[i] + 1)
                continue;
            int L = rp[i] + 1;
            int R = lp[j] - 1;
            if (i == 0 && j == 1)
            {
                if (pre[2][R] - pre[2][L - 1] >= aim)
                {
                    cout << 1 << " " << rp[i] << " ";
                    cout << lp[j] << " " << n << " ";
                    cout << L << " " << R << " ";
                    cout << endl;
                    return;
                }
            }
            if (i == 0 && j == 2)
            {
                if (pre[1][R] - pre[1][L - 1] >= aim)
                {
                    cout << 1 << " " << rp[i] << " ";
                    cout << L << " " << R << " ";
                    cout << lp[j] << " " << n << " ";
                    cout << endl;
                    return;
                }
            }
            if (i == 1 && j == 0)
            {
                if (pre[2][R] - pre[2][L - 1] >= aim)
                {
                    cout << lp[j] << " " << n << " ";
                    cout << 1 << " " << rp[i] << " ";
                    cout << L << " " << R << " ";
                    cout << endl;
                    return;
                }
            }
            if (i == 1 && j == 2)
            {
                if (pre[0][R] - pre[0][L - 1] >= aim)
                {
                    cout << L << " " << R << " ";
                    cout << 1 << " " << rp[i] << " ";
                    cout << lp[j] << " " << n << " ";
                    cout << endl;
                    return;
                }
            }
            if (i == 2 && j == 0)
            {
                if (pre[1][R] - pre[1][L - 1] >= aim)
                {
                    cout << lp[j] << " " << n << " ";
                    cout << L << " " << R << " ";
                    cout << 1 << " " << rp[i] << " ";
                    cout << endl;
                    return;
                }
            }
            if (i == 2 && j == 1)
            {
                if (pre[0][R] - pre[0][L - 1] >= aim)
                {
                    cout << L << " " << R << " ";
                    cout << lp[j] << " " << n << " ";
                    cout << 1 << " " << rp[i] << " ";
                    cout << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
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