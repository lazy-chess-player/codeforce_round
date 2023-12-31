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


void solve()
{
    int n;
    cin >> n;

    vvi M(n, vi(n));

    for (int i = 0; i < n; i++) 
    {
        int cnt = 0;
        for (int j = 0; j < n; j++) 
        {
            cin >> M[i][j];
        }
    }

    if (n == 1)
    {
        cout << "YES" << endl;
        cout << 1 << endl;
        return;
    }

    vi a(n);

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            a[i] = M[i][1];
        else
            a[i] = M[i][0];
        for (int j = 0; j < n; ++j)
        {
            if (j == i)
                continue;
            a[i] &= M[i][j];
        }
    }
    
    bool found = true;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && M[i][j] != (a[i] | a[j]))
            {
                found = false;
                break;
            }
        }
        if (!found)
            break;
    }
    if(found)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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