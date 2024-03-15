#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <bitset>
#include <cmath>

#define endl '\n'

#define ft first
#define sd second

#define yes std::cout<<"Yes\n"
#define no std::cout<<"No\n"


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


void cinv(vi vec, int n)
{
    for (int i = 1; i <= (n); i++)
        cin >> (vec)[i];
}
void rcinv(vi vec, int n)
{
    for (int i = (n); i >= 1; i--)
        cin >> (vec)[i];
}
void coutv(vi vec, int n)
{
    for (int i = 1; i <= (n); i++)
        cout << (vec)[i] << " ";
    cout << '\n';
}
void rcoutv(vi vec, int n)
{
    for (int i = (n); i >= 1; i--)
        cout << (vec)[i] << " ";
    cout << '\n';
}

const int MAXN = 2e5 + 5;
int n;

char board[3][MAXN];
bool vis[3][MAXN];
bool flag = false;

pii d[] = { {-1,0},{1,0},{0,-1} ,{0,1} };

void dfs(int y, int x)
{
    if (flag)
        return;
    if (y < 1 || y>2 || x<1 || x>n)
        return;
    if (board[y][x] == '>')
        x += 1;
    else if (board[y][x] == '<')
        x -= 1;
    if (y < 1 || y>2 || x<1 || x>n)
        return;
    if (y == 2, x == n)
    {
        flag = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!vis[y + d[i].ft][x + d[i].sd] && y + d[i].ft >= 1 && y + d[i].ft <= 2 && x + d[i].sd >= 1 && x + d[i].sd <= n)
        {
            vis[y + d[i].ft][x + d[i].sd] = true;
            dfs(y + d[i].ft, x + d[i].sd);
        }
    }
    return;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1] || s[i] == '?' || s[i + 1] == '?')
            ans = 1;
    }

    for (int i = 2; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < n - i; j++)
        {
            if (s[j] == s[j + i] || s[j] == '?' || s[j + i] == '?')
                v.push_back(j);
        }
        sort(v.begin(), v.end());
        int mx = 1;
        int cnt = 1;
        for (int j = 1; j < v.size(); j++)
        {
            if (v[j] - 1 == v[j - 1])
                cnt += 1;
            else
            {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        mx = max(mx, cnt);
        if (mx >= i)
        {
            ans = max(ans, i);
        }
    }

    cout << 2 * ans << endl;
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