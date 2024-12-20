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
const int N = 2e5 + 5;

const ll mod = 998244353;
ll fact[N], infact[N];

ll qmi(ll a, ll k, ll p = mod) // 快速幂模板
{
    ll res = 1;
    a %= p;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}

// 预处理阶乘的余数和阶乘逆元的余数
void getFact()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

ll C(int a, int b)
{
    if (a < b)
        return 0;
    return (ll)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(n);
    // 统计数组 a 中每个值的出现频次
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> suf(n); // suf 数组用于存储从第 i 个位置开始，到数组末尾的后缀积
    suf[n - 1] = 1;     // 最后一个元素的后缀积设为 1，因为 suf 数组是为每个位置计算贡献做准备的

    // 逆序计算每个位置的后缀积， suf[i] 表示从位置 i 到末尾，每个 mex 值增加的贡献倍数
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1] * qmi(2, cnt[i + 1]) % mod;
    }

    ll ans = 0;            // 最终答案
    vector<ll> f(n);       // f 数组用于记录每个元素对当前 MEX 的贡献
    vector<int> num = cnt; // num 用来逐步减少每个元素的频次，以此来模拟分区过程
    int p = 0;             // 指针 p 用来追踪当前 MEX 的上限

    // 枚举分区数 k，k 从 n 开始逐步减少到 1
    for (int k = n; k >= 1; k--)
    {
        // 找到最大的满足 cnt[p] >= k 的 p 值，p 用于控制当前可以包含的 mex 最大值
        while (p < n && cnt[p] >= k)
        {
            p++; // p 逐步向右移动，直到找到第一个 cnt[p] < k 的元素
        }
        ll res = 1; // 当前分区中子序列贡献的乘积，初始为 1

        // 遍历 [0, p-1] 区间的元素，计算它们的贡献
        for (int i = 0; i < p; i++)
        {
            // num[i] 表示元素 i 还能使用的剩余次数，如果 num[i] >= k，说明该元素还能进入分区
            while (num[i] >= k)
            {
                // 使用组合数计算 cnt[i] 中取出 num[i] 次的方法数，并累加到 f[i] 中
                f[i] = (f[i] + C(cnt[i], num[i])) % mod;
                num[i]--; // 每次使用完 num[i]，它的频次就减少 1
            }
            // 将每个元素 i 的贡献乘以 res，更新 res
            res = res * f[i] % mod;
            // 将当前分区的贡献加到总答案中，同时乘以 suf[i] 表示后缀的贡献
            ans = (ans + res * suf[i] % mod) % mod;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    std::cin >> _;
    getFact();
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：