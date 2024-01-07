# A. Wallet Exchange

**时间限制:** 1秒
**内存限制:** 256兆
**输入:** 标准输入
**输出:** 标准输出

Alice and Bob are bored, so they decide to play a game with their wallets. Alice has `a` coins in her wallet, while Bob has `b` coins in his wallet.

Both players take turns playing, with Alice making the first move. In each turn, the player will perform the following steps in order:

1. Choose to exchange wallets with their opponent, or to keep their current wallets.
2. Remove 1 coin from the player's current wallet. The current wallet cannot have 0 coins before performing this step.

The player who cannot make a valid move on their turn loses. If both Alice and Bob play optimally, determine who will win the game.

爱丽丝和鲍勃很无聊，于是他们决定用自己的钱包玩一个游戏。爱丽丝的钱包里有 $a$ 枚硬币，而鲍勃的钱包里有 $b$ 枚硬币。

双方轮流玩，由爱丽丝先走棋。在每个回合中，玩家将按顺序执行以下步骤：

1.  选择与对手交换钱包，或保留现有钱包。
2.  从玩家当前钱包中取出 $1$ 个硬币。在执行此步骤之前，当前钱包中不能有 $0$ 枚硬币。

无法在自己的回合中做出有效举动的玩家输。如果爱丽丝和鲍勃都以最佳方式下棋，则决定谁将赢得游戏。

## 输入

每个测试包含多个测试用例。第一行包含一个整数 $t$ ( $1 \leq t \leq 1000$ ) - 测试用例的数量。测试用例说明如下。

每个测试用例的第一行也是唯一一行包含两个整数 $a$ 和 $b$ ( $1 \leq a, b \leq 10^9$ )--分别是爱丽丝和鲍勃钱包中的硬币数量。

## 输出

对于每个测试案例，如果 Alice 将赢得游戏，则输出 "Alice"；如果 Bob 将赢得游戏，则输出 "Bob"。

### 示例

#### 输入

```
10
1 1
1 4
5 3
4 5
11 9
83 91
1032 9307
839204 7281
1000000000 1000000000
53110 2024
```

#### 输出

```
Bob
Alice
Bob
Alice
Bob
Bob
Alice
Alice
Bob
Bob
```

### 注意

在第一个测试案例中，游戏示例如下：

- 爱丽丝在第一步中选择不与鲍勃交换钱包。现在， $a=0$ 和 $b=1$。
- 由于爱丽丝的钱包是空的，所以鲍勃必须选择在第 1 步中不交换钱包。现在是 $a=0$ 和 $b=0$。
- 由于爱丽丝和鲍勃的钱包都是空的，爱丽丝无法下一步棋。因此，鲍勃获胜。

在第二个测试案例中，棋局示例如下：

- 爱丽丝在第一步中选择与鲍勃交换钱包。现在， $a=3$ 和 $b=1$。
- 鲍勃选择在第一步中与爱丽丝交换钱包。现在， $a=1$ 和 $b=2$。
- 爱丽丝选择在第 1 步不与鲍勃交换钱包。现在是 $a=0$ 和 $b=2$。
- 由于爱丽丝的钱包是空的，鲍勃只能选择在第 1 步不与爱丽丝交换钱包。现在， $a=0$ 和 $b=1$。
- 由于爱丽丝的钱包是空的，爱丽丝只能选择在第 1 步中与鲍勃交换钱包。现在是 $a=0$ 和 $b=0$。
- 由于爱丽丝的钱包和鲍勃的钱包都是空的，鲍勃无法下一步棋。因此，爱丽丝获胜。

## 解题思路

仔细观察不难发现，每次行动，除非钱包都为$0$，否则一定可以使一个钱包里的硬币$-1$，到自己行动时，钱包都为$0$，则输了。

那么只要计算两个钱包的硬币之和，然后判断一下奇偶性，钱包都为$0$时会传到谁手里谁就行了。

## 题解

```cpp
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <bitset>
#include <cmath>

#define endl '\n'

#define ft first
#define sd second

#define yes std::cout<<"Yes\n";
#define no std::cout<<"No\n";


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

typedef queue <int> qi;
typedef queue <ll> ql;
typedef queue <pii> qpii;
typedef queue <pll> qpll;
typedef queue <psi> qpsi;
typedef queue <psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pll> pqpl;
typedef priority_queue<psi> pqpsl;

typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<string, int> msi;
typedef map<string, ll> msl;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;


void cinv(vi vec,int n) {for (int i = 1; i <= (n); i++)cin >> (vec)[i];}
void rcinv(vi vec, int n) {for (int i = (n); i >= 1; i--)cin >> (vec)[i];}
void coutv(vi vec, int n) { for (int i = 1; i <= (n); i++)cout << (vec)[i] << " "; cout << '\n'; }
void rcoutv(vi vec, int n) { for (int i = (n); i >= 1; i--)cout << (vec)[i] << " "; cout << '\n'; }


void solve()
{
	ll a,b;
	cin>>a>>b;
	if((a+b)%2)
		cout<<"Alice"<<endl;
	else
		cout<<"Bob"<<endl;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
```

# B. Plus-Minus Split

**时间限制:** 1秒  
**内存限制:** 256兆  
**输入:** 标准输入  
**输出:** 标准输出

You are given a string $s$ of length $n$ consisting of characters "+" and "-". $s$ represents an array $a$ of length $n$ defined by $a_i = 1$ if $s_i$ = "+" and $a_i = -1$ if $s_i$ = "-".

You will do the following process to calculate your penalty:

1. Split $a$ into non-empty arrays $b_1, b_2, ..., b_k$ such that $b_1 + b_2 + ... + b_k = a$, where "+" denotes array concatenation.
2. The penalty of a single array is the absolute value of its sum multiplied by its length. In other words, for some array $c$ of length $m$, its penalty is calculated as $p(c) = |c_1 + c_2 + ... + c_m| \cdot m$.
3. The total penalty that you will receive is $p(b_1) + p(b_2) + ... + p(b_k)$.

If you perform the above process optimally, find the minimum possible penalty you will receive.

给定长度为 $n$ 的字符串$s$ 由字符 "+"和"\-"组成。 $s$表示长度为 $n$的数组 $a$ ，如果 $s_i$ 为 "+"，则由$s_i=1$ ；如果$s_i$ 为"-"，则由$s_i=-1$ 。

您将按以下步骤计算罚金：

1.  将 $a$ 分割成非空数组 $b_1,b_2,\ldots,b_k$ ，从而得到 $b_1+b_2+\ldots+b_k=a^\dagger$ ，其中 $+$ 表示数组连接。
2.  单个数组的惩罚值是其和的绝对值乘以长度。换句话说，对于长度为 $m$ 的数组 $c$ ，其惩罚计算结果为 $p(c)=|c_1+c_2+\ldots+c_m| \cdot m$ 。
3.  你将收到的罚金总额为 $p(b_1)+p(b_2)+\ldots+p(b_k)$ 。

如果以最优方式执行上述过程，请找出你将收到的最小惩罚。

$^\dagger$ 将 $a=[3,1,4,1,5]$ 分割成 $(b_1,b_2,\ldots,b_k)$ 的有效方法有 $([3],[1],[4],[1],[5])$ 、 $([3,1],[4,1,5])$ 和 $([3,1,4,1,5])$ ，而将 $a$ 分割成无效方法有 $([3,1],[1,5])$ 、 $([3],[],[1,4],[1,5])$ 和 $([3,4],[5,1,1])$ 。

---

## 输入

每个测试包含多个测试用例。第一行包含一个整数 $t$ ($1 \leq t \leq 1000$) - 测试用例的数量。测试用例说明如下。

每个测试用例的第一行包含一个整数 $n$ ($1 \leq n \leq 5000$) - 字符串 $s$ 的长度。

每个测试用例的第二行包含字符串 $s$ ($s_i \in \{+, -\}$, $|s| = n$)。

请注意，在所有测试用例中， $n$ 的总和不受限制。

---

## 输出

对于每个测试用例，输出一个整数，代表你可能受到的最小惩罚。

### 示例

#### 输入

```
5
1
+
5
-----
6
+-+-+-
10
--+++++++-
20
+---++++-+++++---++-
```

#### 输出

```
1
5
0
4
4
```

### 注意

在第一个测试用例中，我们有 $a = [1]$。我们可以将数组 $a$ 分割为 $[1]$。那么，子数组的惩罚总和为 $p([1]) = 1$。

在第二个测试案例中，我们有 $a = [-1, -1, -1, -1, -1]$。我们可以将数组 $a$ 拆分为 $[-1], [-1], [-1], [-1], [-1]$。那么，子数组的惩罚总和为 $p([-1]) + p([-1]) + p([-1]) + p([-1]) + p([-1]) = 1 + 1 + 1 + 1 + 1 = 5$。

在第三个测试案例中，我们有 $a = [1, -1, 1, -1, 1, -1]$。我们可以将数组 $a$ 拆分为 $[1, -1, 1, -1], [1, -1]$。那么，子数组的惩罚总和为 $p([1, -1, 1, -1]) + p([1, -1]) = 0 + 0 = 0$。

## 解题思路

以划分出的区间的区间和为0为目标进行划分，无法划分出区间和为0的数字就让它自身划分。例如$[+,+,-,+,-,-,+,]$就可以划分成$[+]$和$[+,-,+,-,-,+,]$。然后很容易就可以证出，如果$+$和$-$的数量一致无论怎么排序，区间和一定为$0$;如果不一致，这个区间一定可划分成三个区间，其中两个区间的区间和为零，一个区间包含多于的-或者+。那么答案就是$+$和$-$的数量差

## 题解

```cpp
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <bitset>
#include <cmath>

#define endl '\n'

#define ft first
#define sd second

#define yes std::cout<<"Yes\n";
#define no std::cout<<"No\n";


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

typedef queue <int> qi;
typedef queue <ll> ql;
typedef queue <pii> qpii;
typedef queue <pll> qpll;
typedef queue <psi> qpsi;
typedef queue <psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pll> pqpl;
typedef priority_queue<psi> pqpsl;

typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<string, int> msi;
typedef map<string, ll> msl;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;


void cinv(vi vec,int n) {for (int i = 1; i <= (n); i++)cin >> (vec)[i];}
void rcinv(vi vec, int n) {for (int i = (n); i >= 1; i--)cin >> (vec)[i];}
void coutv(vi vec, int n) { for (int i = 1; i <= (n); i++)cout << (vec)[i] << " "; cout << '\n'; }
void rcoutv(vi vec, int n) { for (int i = (n); i >= 1; i--)cout << (vec)[i] << " "; cout << '\n'; }


void solve()
{
	ll n;cin>>n;
    ll cnt1=0,cnt2=0;
    string s;cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='+')
            cnt1++;
        else
            cnt2++;
    }
    cout<<abs(cnt1-cnt2)<<endl;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
```

# C. Grouping Increases

**时间限制:** 1秒  
**内存限制:** 256兆  
**输入:** 标准输入  
**输出:** 标准输出

You are given an array $a$ of size $n$. You will do the following process to calculate your penalty:

1. Split array $a$ into two (possibly empty) subsequences† $s$ and $t$ such that every element of $a$ is either in $s$ or $t‡$.
2. For an array $b$ of size $m$, define the penalty $p(b)$ of an array $b$ as the number of indices $i$ between $1$ and $m−1$ where $b_i < b_{i+1}$.
3. The total penalty you will receive is $p(s) + p(t)$.

If you perform the above process optimally, find the minimum possible penalty you will receive.

给你一个大小为 $n$ 的数组 $a$ 。你将按以下步骤计算罚金：

1.  将数组 $a$ 分割成两个(可能为空)子序列 $^\dagger$ 和 $t$ ，这样 $a$ 中的每个元素要么在 $s$ 中，要么在 $s$ 中。 $s$ 和 $t$ ，这样 $a$ 中的每个元素要么在 $s$ 中，要么在 $t^\ddagger$ 中。
2.  对于大小为 $m$ 的数组 $b$ ，定义数组 $b$ 的惩罚 $p(b)$ 为 $1$ 和 $m - 1$ 之间索引 $i$ 的个数，其中 $b_i< b_{i + 1}$ .
3.  你将得到的总惩罚为 $p(s) + p(t)$ 。

如果以最优方式执行上述过程，请求得可能收到的最小惩罚。

$^\dagger$ 如果 $x$ 可以通过删除几个(可能是零个或全部)元素从 $y$ 得到，那么序列 $x$ 就是序列 $y$ 的子序列。

$^\ddagger$ 将数组 $a=[3,1,4,1,5]$ 拆分为 $(s,t)$ 的有效方法有 $([3,4,1,5],[1])$ 、 $([1,1],[3,4,5])$ 和 $([],[3,1,4,1,5])$ ，而拆分为 $a$ 的无效方法有 $([3,4,5],[1])$ 、 $([3,1,4,1],[1,5])$ 和 $([1,3,4],[5,1])$ 。

---

## 输入

每个测试包含多个测试用例。第一行包含一个整数 $t$ ($1 \leq t \leq 10^4$) - 测试用例的数量。测试用例说明如下。

每个测试用例的第一行包含一个整数 $n$ ($1 \leq n \leq 2 \times 10^5$) - 数组 $a$ 的大小。

第二行包含 $n$ 个整数 $a_1, a_2, ..., a_n$ ($1 \leq a_i \leq n$) - 数组 $a$ 的元素。

保证所有测试用例的 $n$ 之和不超过 $2 \times 10^5$。

---

## 输出

对于每个测试用例，输出一个整数，代表你可能受到的最小惩罚。

### 示例

#### 输入

```
5
5
1 2 3 4 5
8
8 2 3 1 1 7 4 3
5
3 3 3 3 3
1
1
2
2 1
```

#### 输出

```
3
1
0
0
0
```

### 注意

在第一个测试用例中，拆分 $a$ 的可能方法是 $s=[2,4,5]$ 和 $t=[1,3]$。罚则是 $p(s) + p(t) = 2 + 1 = 3$。

在第二个测试用例中，拆分 $a$ 的可能方式是 $s=[8,3,1]$ 和 $t=[2,1,7,4,3]$。罚则为 $p(s) + p(t) = 0 + 1 = 1$。

在第三个测试用例中，拆分 $a$ 的可能方式是 $s=[]$ 和 $t=[3,3,3,3,3]$。罚则为 $p(s) + p(t) = 0 + 0 = 0$。

## 解题思路

我们可以将题目转化一下，这样思考：一开始有两个盒子，每个盒子可以装下比自己小的一个盒子，装下比自己小的盒子之后，容量就会变小，如果两个盒子都装不下，我们就可以花费代价去换一个任意大的盒子，无论多大，花费的代价都是1。现在有一堆盒子等我们装起来，把所有盒子装下的代价是多少。

我们可以一开始看作拥有两个无限大容量的盒子，在装盒子的过程中，如果待装的盒子比现有的两个盒子容量都小，那么肯定是用更小的那个盒子去装，如果用更大的盒子去装，那么浪费的容量就会更大；如果待装的盒子比小盒子大，比大盒子小，那么肯定装进大盒子里，没必要花费代价去换一个盒子；如果待装的盒子比两个盒子都大，那肯定是换掉更小的那个盒子，因为换多大的盒子的代价都一样，既然花的钱一样，肯定是把小的换了留大的。

所以只需要维护两个盒子的实时容量，然后统计换盒子花费的代价就行。

## 题解

```cpp
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <bitset>
#include <cmath>

#define endl '\n'

#define ft first
#define sd second

#define yes std::cout<<"Yes\n";
#define no std::cout<<"No\n";


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

typedef queue <int> qi;
typedef queue <ll> ql;
typedef queue <pii> qpii;
typedef queue <pll> qpll;
typedef queue <psi> qpsi;
typedef queue <psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pll> pqpl;
typedef priority_queue<psi> pqpsl;

typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<string, int> msi;
typedef map<string, ll> msl;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;


void cinv(vi vec, int n) { for (int i = 1; i <= (n); i++)cin >> (vec)[i]; }
void rcinv(vi vec, int n) { for (int i = (n); i >= 1; i--)cin >> (vec)[i]; }
void coutv(vi vec, int n) { for (int i = 1; i <= (n); i++)cout << (vec)[i] << " "; cout << '\n'; }
void rcoutv(vi vec, int n) { for (int i = (n); i >= 1; i--)cout << (vec)[i] << " "; cout << '\n'; }


void solve()
{
    ll n; cin >> n;
    int minbox=INT32_MAX;
    int maxbox=INT32_MAX;
    int now;
    int cost=0;
    for(int i=0;i<n;i++)
    {
        cin>>now;
        if(minbox>maxbox)// 只需要知道小盒子和大盒子的容量分别是多少就行
            swap(minbox,maxbox);
        if(now<=minbox)// 比小盒子更小，装进小盒子里
            minbox=now;
        else if(now>maxbox)// 比大盒子更大，花费1代价换掉小盒子
        {
            cost++;
            minbox=now;
        }
        else// 比大盒子小且比小盒子大，装进大盒子
            maxbox=now;
    }
    cout<<cost<<endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
```

