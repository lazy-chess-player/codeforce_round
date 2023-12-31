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

#define x first
#define y second
#define endl '\n'

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

bool checkU(int a, int b)
{
	return b > 0;
}
bool checkD(int a, int b)
{
	return b < 0;
}
bool checkR(int a, int b)
{
	return a > 0;
}
bool checkL(int a, int b)
{
	return a < 0;
}

void solve()
{
	int n; cin >> n;
	vpii d(n);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> d[i].x >> d[i].y;
	}
	int D = 0;
	for (int i = 0; i < n; i++)
	{
		if (d[i].y < 0)
			D = 1;
	}
	int U = 0;
	for (int i = 0; i < n; i++)
	{
		if (d[i].y > 0)
			U = 1;
	}
	int R = 0;
	for (int i = 0; i < n; i++)
	{
		if (d[i].x > 0)
			R = 1;
	}
	int L = 0;
	for (int i = 0; i < n; i++)
	{
		if (d[i].x < 0)
			L = 1;
	}
	cnt = U + R + L + D;
	if (cnt > 3)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
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