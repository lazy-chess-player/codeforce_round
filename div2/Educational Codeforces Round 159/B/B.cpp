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

#define fi first
#define se second
#define endl '\n'
#define min(a,b) (a)<(b)?(a):(b)

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef pair<string, int> psi;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pss> vpss;
typedef vector<vi> vvi;

typedef queue <int> qi;
typedef queue <ll> ql;
typedef queue <pii> qpii;
typedef queue <psi> qpsi;

typedef priority_queue<int> pqi;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;

typedef unordered_map<int, int> umapii;
typedef unordered_map<string, int> umapsi;

const int N = 1e5 + 5;

inline ll read()
{
	register ll x = 0, y = 1;
	register char ch = getchar();
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

inline void write(ll x)
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

ll n, P, l, t;
ll taskNum;


void solve()
{
	n = read();
	P = read();
	l = read();
	t = read();
	taskNum = (n + 6) / 7;
	for (int i = n; P > 0 && n > 0 && i > 0; i--)
	{
		if (taskNum > 1)
		{
			P -= 2 * t;
			taskNum -= 2;
			n--;
			P -= l;
		}
		else if (taskNum == 1)
		{
			P -= t;
			taskNum--;
			n--;
			P -= l;
		}
		else
		{
			n -= (P + l - 1) / l;
			break;
		}
	}
	write(n);
	printf("\n");
}

int main()
{
	int testNum = 1;
	testNum = read();
	while (testNum--)
	{
		solve();
	}
	return 0;
}