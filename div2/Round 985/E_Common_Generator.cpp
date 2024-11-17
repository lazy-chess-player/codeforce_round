#include <bits/stdc++.h>

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
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

#define RED cout << "\033[91m"     // 红色
#define GREEN cout << "\033[92m"   // 绿色
#define YELLOW cout << "\033[93m"  // 蓝色
#define BLUE cout << "\033[94m"    // 品红
#define MAGENTA cout << "\033[95m" // 青色
#define CYAN cout << "\033[96m"    // 青色
#define RESET cout << "\033[0m"    // 重置

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t i128;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<string, ll> psl;

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

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
const int N = 4e5;

vector<int> minp;   // 存储每个数的最小质因子
vector<int> primes; // 存储找到的所有质数

// 欧拉筛函数
void sieve(int n)
{
    minp.assign(n + 1, 0); // 初始化最小质因子数组
    primes.clear();        // 清空质数数组

    for (int i = 2; i <= n; i++)
    {
        if (minp[i] == 0)
        {                        // 如果 minp[i] 仍为 0，说明 i 是质数
            minp[i] = i;         // 记录 i 的最小质因子为自身
            primes.push_back(i); // 将 i 添加到质数列表中
        }

        // 遍历已找到的质数
        for (auto p : primes)
        {
            if (i * p > n)
            { // 如果 i * p 超过 n，停止
                break;
            }
            minp[i * p] = p; // 记录 i * p 的最小质因子
            if (p == minp[i])
            { // 如果当前质数等于 i 的最小质因子，停止
                break;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    int cntPri = 0;
    int pri = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (minp[a[i]] == a[i])
        {
            cntPri++;
            pri = a[i];
        }
    }
    if (cntPri >= 2)
    {
        cout << "-1\n";
        return;
    }
    if (cntPri == 0)
    {
        cout << "2\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == pri)
            continue;
        int v = a[i] & 1 ? a[i] - minp[a[i]] : a[i];
        if (pri * 2 > v)
        {
            cout << "-1\n";
            return;
        }
    }
    cout << pri << "\n";
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    std::cin >> _;
    sieve(N);
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：