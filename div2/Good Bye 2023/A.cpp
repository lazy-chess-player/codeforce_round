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
	int n, k;
	cin >> n >> k;
	int cnt1 = 0;
	int cnt7 = 0;
	int cnt17 = 0;
	vi a;
	bool flag = true;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp == 1)
		{
			cnt1++;
		}
		else if(temp==7)
		{
			cnt7++;
		}
		else if(temp==17)
		{
			cnt17++;
		}
		else if(temp==289)
		{
			cnt17 += 2;
		}
		else if(temp==17)
		{
			cnt17++;
		}
		else if(temp==119)
		{
			cnt17++;
			cnt7++;
		}
		else if(temp==2023)
		{
			cnt17 += 2;
			cnt7++;
		}
		else
		{
			flag = false;
		}
	}
	int d7 = 1 - cnt7;
	int d17 = 2 - cnt17;
	temp = 1;
	k --;
	if (d7 >= 0 && d17 >= 0)
	{
		for(int i = 0; i < d7; i++)
		{
			temp *= 7;
		}
		for (int i = 0; i < d17; i++)
		{
			temp *= 17;
		}
		a.push_back(temp);
		for (int i = 0; i < k; i++)
		{
			a.push_back(1);
		}
	}
	else
		flag = false;
	if (flag)
	{
		cout << "YES" << endl;
		for (int i = 0; i < a.size(); i++)
			cout << a[i] << " ";
		cout << endl;
	}
	else
		cout << "NO" << endl;
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