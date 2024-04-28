# CodeForces Round 941(div2)题解.md

## [A. Card Exchange](https://codeforces.com/contest/1966/problem/A)

### 题目翻译

你有一手 *n* 张牌，每张牌上都写着一个数字，还有一个固定整数 *k*。你可以多次进行下面的运算：

- 从手中的 *k* 张牌中选择任意一张数字相同的牌。
- 将这些牌换成 *k-1* 张牌，每张牌上可以有你选择的任何数字（包括你刚刚换的牌上写的数字）。

在这个过程结束时，你手中最少有多少张牌？

#### 输入

输入的第一行包含一个整数 *t*（$1 ≤ t ≤ 500$） - 测试用例的数量。

每个测试用例的第一行包含两个整数 *n* 和 *k*（$1 ≤ n ≤ 100$，$2 ≤ k ≤ 100$）--分别是您拥有的纸牌数量，以及您在每次操作中交换的纸牌数量。

每个测试用例的下一行包含 *n* 个整数 *c1,c2,…,cn*（$1 ≤ ci ≤ 100$）- 写在卡片上的数字。

#### 输出
对于每个测试用例，输出一个整数，即经过任意次数的操作后，手中所剩纸牌的最少数量。

#### 示例
输入
```
7
5 3
4 1 1 4 4
1 10
7
7 2
4 2 1 100 5 2 3
10 4
1 1 1 1 1 1 1 1 1 1
5 2
3 8 1 48 7
6 2
10 20 30 10 20 40
6 3
10 20 30 10 20 40
```

输出
```
2
1
1
3
5
1
6
```

### 解题思路

由于$k$张牌可以换成$k-1$张任意牌，所以只有有一种牌的数量大于等于$k$，我们就可以把所有牌换成任意牌，所以最后会剩下$k-1$张。

### 题解

```cpp
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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
    int n, k;
    cin >> n >> k;
    vi a(n);
    mii mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    bool flag = false;
    for (auto x : mp)
    {
        if (x.sd >= k)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << k - 1 << endl;
    else
        cout << n << endl;
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
```

## [B. Rectangle Filling](https://codeforces.com/contest/1966/problem/B)

### 题目翻译

有一个由白色和黑色方格组成的 $n \times m$ 网格。在一次操作中，您可以选择任意两个相同颜色的方格，并将它们之间的子矩形中的所有方格都染成相同的颜色。

具体来说，如果您选择了位置 $(x_1,y_1)$ 和 $(x_2,y_2)$，这两个位置当前的颜色都是 $c$，那么就可以将 $\min(x_1,x_2) \leq x \leq \max(x_1,x_2)$ 和 $\min(y_1,y_2) \leq y \leq \max(y_1,y_2)$ 所在的所有 $(x,y)$ 的颜色设置为 $c$。

在进行任意次数（可能为零）的运算后，网格中所有方格的颜色是否可能相同？

#### 输入
输入的第一行包含一个整数 $t$（$1 \leq t \leq 10^4$） - 测试用例的数量。

每个测试用例的第一行包含两个整数 $n$ 和 $m$（$1 \leq n,m \leq 500$） - 分别是网格的行数和列数。

接下来的每行 $n$ 都包含 $m$ 个字符 'W' 和 'B' - 网格方格的初始颜色。

#### 输出
对于每个测试用例，如果可以使网格中所有方格的颜色相同，则打印 "YES"，否则打印 "NO"。

您可以用任何大小写（大写或小写）输出答案。例如，字符串 "yEs"、"yes"、"Yes" 和 "YES" 将被识别为肯定回答。

#### 示例
输入
```
8
2 1
W
B
6 6
WWWWBW
WBWWWW
BBBWWW
BWWWBB
WWBWBB
BBBWBW
1 1
W
2 2
BB
BB
3 4
BWBW
WBWB
BWBW
4 2
BB
BB
WW
WW
4 4
WWBW
BBWB
WWBB
BBBB
1 5
WBBWB
```

输出
```
NO
YES
YES
YES
YES
NO
YES
NO
```

#### 注
在第一个示例中，无论如何操作，都无法改变任何一个方格的颜色，因此输出 NO。

第二个示例是上面图片中的情况。如图所示，经过两次操作后，所有方格都可能变成白色，因此输出 YES。

在第三个和第四个示例中，所有方格的颜色已经是相同的，因此输出 YES。

在第五个示例中，我们可以在两次操作中完成所有操作。首先，选择位置 $(2,1)$ 和 $(1,4)$，将所有满足 $1 \leq x \leq 2$ 和 $1 \leq y \leq 4$ 的方格染成白色。然后，选择位置 $(2,1)$ 和 $(3,4)$，将所有满足 $2 \leq x \leq 3$ 和 $1 \leq y \leq 4$ 的方格染成白色。经过这两次操作后，所有方格都是白色的。

### 解题思路

如果要把矩阵全部变为同一个颜色，贪心的想肯定是选取四个角上的点。所以先取四个角上的点，判断是否存在对角线上的两个角相同，如果存在，则可以全部染色。在判断在一条边界上的两个角是否相同，如果相同，则看对边上是否存在存在相同的点，如果存在则可以全部染色。判断完四条边之后如果都不能，则输出"NO"。

### 题解

```cpp
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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
    int n, m;
    cin >> n >> m;
    vvi a(n + 1, vi(m + 1, 0));
    char t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> t;
            if (t == 'B')
                a[i][j] = 1;
        }
    }
    int lu = a[1][1];
    int ld = a[n][1];
    int ru = a[1][m];
    int rd = a[n][m];
    if (n == 1)
    {
        if (lu == ru)
            YES;
        else
            NO;
        return;
    }
    if (m == 1)
    {
        if (lu == ld)
            YES;
        else
            NO;
        return;
    }
    bool flag = false;
    if (lu == rd || ld == ru)
    {
        YES;
        return;
    }
    if (lu == ru)
    {
        for (int i = 1; i <= m; i++)
        {
            if (a[n][i] == lu)
            {
                YES;
                return;
            }
        }
    }
    if (ld == rd)
    {
        for (int i = 1; i <= m; i++)
        {
            if (a[1][i] == ld)
            {
                YES;
                return;
            }
        }
    }
    if (lu == ld)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i][m] == lu)
            {
                YES;
                return;
            }
        }
    }
    if (ru == rd)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i][1] == ru)
            {
                YES;
                return;
            }
        }
    }
    NO;
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
```

## [C. Everything Nim](https://codeforces.com/contest/1966/problem/C)

### 题目翻译

爱丽丝和鲍勃正在玩一个关于 $n$ 堆石子的游戏。轮到每个玩家时，他们都会选择一个正整数 $k$，这个正整数最多等于最小的非空堆的大小，然后从每个非空堆中一次性取出 $k$ 个石子。第一个无法下棋的棋手（因为所有堆都是空的）就算输。

既然爱丽丝先下，那么如果双方都以最佳方式下棋，谁会赢呢？

#### 输入
输入的第一行包含一个整数 $t$（$1 \leq t \leq 10^4$）-- 测试用例的数量。

每个测试用例的第一行都包含一个整数 $n$（$1 \leq n \leq 2 \times 10^5$） - 游戏中的堆数。

每个测试用例的下一行包含 $n$ 个整数 $a_1,a_2,\ldots,a_n$（$1 \leq a_i \leq 10^9$），其中 $a_i$ 是第 $i$ 堆中的初始石子数量。

保证所有测试用例的 $n$ 之和不超过 $2 \times 10^5$。

#### 输出
对于每个测试用例，打印一行，写上获胜者的名字（假设双方都发挥出最佳水平）。如果 Alice 获胜，则打印 "Alice"，否则打印 "Bob"（不带引号）。

#### 示例
输入
```
7
5
3 3 3 3 3
2
1 7
7
1 3 9 7 4 2 100
3
1 2 3
6
2 1 3 4 2 4
8
5 7 2 9 6 3 3 2
1
1000000000
```

输出
```
Alice
Bob
Alice
Alice
Bob
Alice
Alice
```

#### 注
在第一个测试案例中，爱丽丝只要在第一轮选择 $k=3$ ，就能一次性清空所有牌堆，从而获胜。

在第二个测试案例中，爱丽丝必须在第一轮选择 $k=1$ ，因为有一堆大小为1的牌。

因此鲍勃可以在下一轮选择 $k=6$ 获胜。

### 解题思路

由于对一堆进行取操作等同于对所有堆进行取操作，所以如果一堆取完，那么相当于同等数量的所有堆取完，所有数量相同的堆可以合并。

观察发现，如果堆的数量存在逐级$+1$的递增序列，在这个递增序列取完之前，两个人都无法自由行动。

当递增序列取完，这个游戏就变成了一个普通的$NIM$游戏。

所以，只要先对堆进行去重操作，然后求一下$mex$，然后判断一下奇偶性，看递增序列取完之后是谁先手。如果剩下的堆的数量大于等于$1$，则先手必胜，否则必败

### 题解

```cpp
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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

const string t1 = "Alice";
const string t2 = "Bob";

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    a.erase(unique(all(a)), a.begin());
    int m = a.size();
    int mex = 0;
    int i = 1;
    while (i < m && a[i] == a[i - 1] + 1)
    {
        i++;
        mex++;
    }
    if (i == m)
    {
        if (mex & 1)
            cout << t1 << endl;
        else
            cout << t2 << endl;
        return;
    }
    if (mex & 1)
    {
        if (a[i] - mex > 1)
            cout << t2 << endl;
        else
            cout << t1 << endl;
    }
    else
    {
        if (a[i] - mex > 1)
            cout << t1 << endl;
        else
            cout << t2 << endl;
    }
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
```

## [D. Missing Subsequence Sum](https://codeforces.com/contest/1966/problem/D)

### 题目翻译

给定两个整数 $n$ 和 $k$。找到一个大小最多为 25 的非负整数序列 $a$，使得满足以下条件：

1. 没有和为 $k$ 的 $a$ 的子序列。
2. 对于 $v \neq k$ 所有 $1 \leq v \leq n$，存在一个和为 $v$ 的 $a$ 的子序列。

#### 输入
第一行包含一个整数 $t$（$1 \leq t \leq 1000$）-- 测试用例的数量。

每个测试用例由一行组成，包含两个整数 $n$ 和 $k$（$2 \leq n \leq 10^6$，$1 \leq k \leq n$）-- 上述参数。

保证所有测试用例中 $n$ 的总和不超过 $10^7$。

#### 输出
每个测试用例的第一行输出应包含一个整数 $m$（$1 \leq m \leq 25$）- 您所选序列的大小。

每个测试用例的第二行输出应包含 $m$ 个整数 $a_i$（$0 \leq a_i \leq 10^9$）- 您所选序列的元素。

如果有多个解决方案，请打印任意一个。

#### 示例
输入
```
5
2 2
6 1
8 8
9 3
10 7
```

输出
```
1
1
5
2 3 4 5 6
7
1 1 1 1 1 1 1
4
7 1 4 1
4
1 2 8 3
```

#### 注
在第一个例子中，我们只需要一个与 1 相加的子序列，而不需要一个与 2 相加的子序列。因此，数组 $a=[1]$ 就足够了。

在第二个例子中，所有的元素都大于 $k=1$，所以没有一个子序列能与 1 相加。数组中存在 1 和 $n$ 之间的所有其他整数，因此有大小为 1 的子序列与这些数字相加。

### 解题思路

对于一个数$x$，如果我们要获得一个长度为$m$的序列$a$，使得$\sum _{i=1}^{m}a$，那么我们可以将$x$转化成二进制形式，$x$上二进制位为$1$的$2$的幂，就是我们所需要的序列。

例如$x=37$，它的二进制序列为$100101$，那么我们所需要的序列就是$1(000001),4(000100),32(100000)$。

综上，对于序列$a=2^0,2^1,2^2\dots2^n$，我们可以拼凑出$1\sim 2^{n+1}-1$的所有数。

因此，我们可以可以很容易的构造出元素和范围$[1，2^i-1],2^i<=k$​的序列。

对于元素和范围为$[2^i, k-1]$的序列，我们只需要把$k-2^{i-1}$添加进答案中即可，因为我们已经可以构造出元素和$[1,2^{i-1}-1]$的所有数，给这些数加上$k-2^{i-1}$，我们就可以构造出元素和$[k-2^{i-1}+1,k-1]$的所有数，且任意子序列之后不会为$k$。

对于元素和范围为$[k+1, n]$的序列，我们可以使用$bitset$存储已经构造出元素和的数，如果这个数不存在，则把它添加进答案中，并更新$bitset$。

由于序列长度$m\leq25$，所有我们只需跟新不超过$m$次，时间复杂度为$O(mn)$，不会超时。

### 题解

```cpp
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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

const int N = 2e6 + 5;
bitset<N> vis;

void init()
{
    vis.reset();
    vis[0] = 1;
}

void solve()
{
    init();
    int n, k;
    cin >> n >> k;
    vi ans;
    int bit = 1;
    while (bit * 2 - 1 < k)
    {
        ans.eb(bit);
        for (int i = n; i >= bit; i--)
        {
            vis.set(i, vis[i] || vis[i - bit]);
        }
        bit <<= 1;
    }
    int t = k - bit;
    if (t > 0)
    {
        ans.eb(t);
        for (int i = n; i >= t; i--)
        {
            vis.set(i, vis[i] || vis[i - t]);
        }
    }
    for (bit = k + 1; bit <= n; bit++)
    {
        if (!vis[bit])
        {
            ans.eb(bit);
            for (int i = n; i >= bit; i--)
            {
                vis.set(i, vis[i] || vis[i - bit]);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
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
```

