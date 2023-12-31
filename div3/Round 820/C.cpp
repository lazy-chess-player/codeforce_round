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
 
pair<char, int> tiles[MAXN];
 
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    char beg = s[0];
    char en = s[n - 1];
    for (int i = 0; i < n; i++)
    {
        tiles[i].first = s[i];
        tiles[i].second = i + 1;
    }
    sort(tiles + 1, tiles + n - 1);
    vi ans;
    bool reversed = false;
    if (beg > en)
    {
        swap(beg, en);
        reversed = true;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (tiles[i].first >= beg && tiles[i].first <= en)
            ans.emplace_back(tiles[i].second);
    }
    int cost = en - beg;
    int step = 2 + ans.size();
    cout << cost << " " << step << endl;
    cout << 1 << " ";
    if (reversed)
        reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << n;
    cout << endl;
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