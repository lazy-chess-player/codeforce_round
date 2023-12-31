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

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
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

map<string, pii> act = { {"DR",{1,1,}} ,{"DL",{1,-1}},{"UR",{-1,1}},{"UL",{-1,-1}} };

void solve()
{
	int n, m, i1, j1, i2, j2;
	string s;
	cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> s;
    ll cnt = 0;
    int vx = act[s].first;
    int vy = act[s].second;
    int f,p, q, dx, dy;
    set<tuple<int, int, int, int> > st;
    while (i1 != i2 || j1 != j2) 
    {
        if (st.count(make_tuple(i1, j1, vx, vy)) != 0) 
        {
            cout << "-1\n";
            return;
        }
        st.emplace(i1, j1, vx, vy);
        f = 0;
        if (i1 == 1 && vx == -1) 
            vx = 1, f = 1;
        if (i1 == n && vx == 1) 
            vx = -1, f = 1;
        if (j1 == 1 && vy == -1) 
            vy = 1, f = 1;
        if (j1 == m && vy == 1)
            vy = -1, f = 1;
        if (vx == 1) 
            p = n - i1;
        else 
            p = i1 - 1;
        if (vy == 1) 
            q = m - j1;
        else 
            q = j1 - 1;
        p = min(p, q);
        cnt += f;
        dx = vx * abs(i1 - i2);
        dy = vy * abs(j1 - j2);
        if (abs(dx) == abs(dy) && i2 - i1 == dx && j2 - j1 == dy) 
            break;
        i1 += vx * p;
        j1 += vy * p;
    }
    cout << cnt << endl;
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