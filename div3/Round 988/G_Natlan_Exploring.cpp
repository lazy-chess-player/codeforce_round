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

const int N = 1e6 + 5; // 假设最大范围为 1000000
int pri[N];            // 存储所有素数
int minp[N];           // minp[x] 存储 x 的最小质因子
int cnt;               // 记录素数数量

const int mod = 998244353;
// 欧拉筛函数
void sieve(int n)
{
    cnt = 0; // 初始化素数计数器
    for (int i = 2; i <= n; i++)
    {
        if (minp[i] == 0)
        {                   // 如果 minp[i] 为 0，说明 i 是素数
            minp[i] = i;    // 记录 i 的最小质因子为自身
            pri[cnt++] = i; // 存储素数
        }
        // 利用已找到的素数进行筛选
        for (int j = 0; j < cnt && pri[j] <= n / i; j++)
        {
            minp[pri[j] * i] = pri[j]; // 筛掉 i * primes[j]，并记录最小质因子
            if (i % pri[j] == 0)
                break; // 防止重复筛选
        }
    }
}

vi func(int x)
{
    vi f;
    while (x > 1)
    {
        int p = minp[x];
        f.eb(p);
        while (x % p == 0)
            x /= p;
    }
    return f;
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxA = *max_element(all(a));
    sieve(maxA);
    vl f(n + 1);
    f[1] = 1;
    vl g(maxA + 1);
    vi primes = func(a[0]);
    int m = primes.size();
    for (int mask = 0; mask < (1 << m); mask++)
    {
        ll d = 1;
        for (int b = 0; b < m; b++)
        {
            if (mask & (1 << b))
                d *= primes[b];
        }
        if (d > maxA)
            continue;
        g[d] = (g[d] + f[1]) % mod;
    }
    ll tot = f[1];
    for (int i = 2; i <= n; i++)
    {
        vi p = func(a[i - 1]);
        int num = p.size();
        ll sum = 0;
        for (int mask = 0; mask < (1 << num); mask++)
        {
            ll d = 1;
            bool flag = true;
            for (int b = 0; b < num; b++)
            {
                if (mask & (1 << b))
                {
                    d *= p[b];
                    if (d > maxA)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag)
                continue;
            int mu = (__builtin_popcount(mask) % 2 == 0) ? -1 : 1;
            sum = (sum + mu * g[d] + mod) % mod;
        }
        f[i] = (tot + sum + mod) % mod;
        for (int mask = 0; mask < (1 << num); mask++)
        {
            ll d = 1;
            for (int b = 0; b < num; b++)
            {
                if (mask & (1 << b))
                    d *= p[b];
            }
            if (d > maxA)
                continue;
            g[d] = (g[d] + f[i]) % mod;
        }
        tot = (tot + f[i]) % mod;
    }
    cout << f[n] << "\n";
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
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