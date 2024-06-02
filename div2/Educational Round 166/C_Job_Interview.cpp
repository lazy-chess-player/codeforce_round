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

typedef struct people
{
    ll a;
    ll b;
    int job;   // 被分配到了a职位就是1，b职位就是2
    bool lose; // 是否浪费了能力
} people;

void solve()
{
    int n, m;
    cin >> n >> m;
    int N = n + m + 1;
    vector<people> p(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> p[i].a;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> p[i].b;
    }
    // 能力总和
    ll sum = 0;
    // 哪种能力被浪费了
    int sta = 0;
    for (int i = 1; i <= N; i++)
    {
        if (p[i].a > p[i].b)
        {
            // a职位减1
            n--;
            // a职位没有了
            if (n < 0)
            {
                sta = 1; // 有人的a能力被浪费了
                sum += p[i].b;
                p[i].job = 2;     // 这个人被分配到了b职位
                p[i].lose = true; // 他的能力被浪费了
            }
            else
            {
                sum += p[i].a;
                p[i].job = 1;      // 这个人被分配到了a职位
                p[i].lose = false; // 他没有能力被浪费
            }
        }
        else
        {
            // b职位减1
            m--;
            // b职位没有了
            if (m < 0)
            {
                sta = 2; // 有人的b能力被浪费了
                sum += p[i].a;
                p[i].job = 1;     // 这个人被分配到了a职位
                p[i].lose = true; // 他的能力被浪费了
            }
            else
            {
                sum += p[i].b;
                p[i].job = 2;      // 这个人被分配到了b职位
                p[i].lose = false; // 他没有能力被浪费
            }
        }
    }
    // 最近被浪费的能力值
    vl nearest_loss(N + 1);
    // 从后往前遍历
    for (int i = N; i >= 1; i--)
    {
        // 如果这个人能力被浪费了，那么最近被浪费的能力值就是他能力值和另一个能力值之差的绝对值
        if (p[i].lose)
            nearest_loss[i] = abs(p[i].a - p[i].b);
        // 如果这个人能力没有被浪费，那么最近被浪费的能力值就是下一个人的最近被浪费的能力值
        else
            nearest_loss[i] = nearest_loss[i + 1];
    }
    // 从前往后输出
    for (int i = 1; i <= N; i++)
    {
        // 输出总和减去当前的人的能力值，判断一下他是否空出了位置给能力被浪费的人，是的话加上最近被浪费的能力值
        cout << sum - (p[i].job == 1 ? p[i].a : p[i].b) + (p[i].job == sta ? nearest_loss[i] : 0) << " ";
    }
    cout << endl;
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