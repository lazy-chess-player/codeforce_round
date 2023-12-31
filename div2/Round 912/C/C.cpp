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

void solve()
{
	int n; cin >> n;
	vl nums(n+1);
	vl sums(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
		sums[i] = nums[i] + sums[i - 1];
	}
	vector<vl> dp(n + 1, vl(n + 1, 0));

	for (int len = 1; len <= n; len++)
	{
		for (int i = 1; i + len <= n; i++)
		{
			int j = i + len - 1;
			dp[i][j] = INT_MAX;

			for (int k = i; k < j; k++)
			{
				dp[i][j] = max(dp[i][j], );
			}
		}

	}

	cout << dp[1][n];
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