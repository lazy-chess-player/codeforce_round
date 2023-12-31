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
 
const int MAXN = 2e5 + 5;
 
 
void solve()
{
    ll res = 4;
    ll ans1 = 0, ans2 = 0;
    while (1) 
    {
        cout << "? " << 1 << ' ' << res << endl;
        cin >> ans1;
        if (ans1 == -1) 
        {
            cout << "! " << res - 1 << endl;
            return;
        }
        cout << "? " << res << ' ' << 1 << endl;
        cin >> ans2;
        if (ans1 != ans2)
        {
            cout << "! " << ans1 + ans2 << endl;
            return;
        }
        res++;
    }
}
 
int main()
{
	ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}