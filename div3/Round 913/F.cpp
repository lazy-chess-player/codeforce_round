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

const int MAXN = 1e5 + 5;

int n;

void solveF()
{
	cin >> n;
	vi nums(2*n);
	vi temps(n);
	int opt1 = INT32_MAX;
	int opt2 = INT32_MAX;
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> temps[i];
		nums[n + i] = nums[i] = temps[i];
	}
	vi temp1 = temps;
	sort(temp1.begin(), temp1.end());
	if (temps == temp1)
	{
		cout << 0 << endl;
		return;
	}
	vi temp2 = temps;
	reverse(temp2.begin(), temp2.end());
	vi temp3 = temp2;
	sort(temp2.begin(), temp2.end());
	if(temp2 == temp3)
	{
		cout << 1 << endl;
		return;
	}
	int start = 0;
	int mn = INT32_MAX;
	for (int i = 0; i < n; i++)
	{
		if(nums[i]<=mn&&(i==0||nums[i-1]>nums[i]))
		{
			start = i;
			mn = nums[i];
		}
	}
	int cnt1 = 1;
	for (int i = start + 1; i < start + n; i++)
	{
		if (nums[i] >= nums[i - 1])
		{
			if (i > n)
				cnt1++;
		}
		else
		{
			cnt1 = -1;
			break;
		}
	}
	if (cnt1 != -1)
		opt1 = min(n - cnt1, cnt1 + 2);
	start = 0;
	int mx = INT32_MIN;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] >= mx && (i == 0 || nums[i - 1] < nums[i]))
		{
			start = i;
			mx = nums[i];
		}
	}
	int cnt2 = 1;
	for (int j = start + 1; j < start + n; j++)
	{
		if (nums[j] <= nums[j - 1])
		{
			if (j > n)
				cnt2++;
		}
		else
		{
			cnt2 = -1;
			break;
		}
	}
	if (cnt2 != -1)
		opt2 = min(n - cnt2 + 1, cnt2 + 1);
	if (cnt1 == -1 && cnt2 == -1)
		opt1 = -1;
	cout << min(opt1, opt2) << endl;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--)
	{
		solveF();
	}
	return 0;
}