#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cstring>
#include <string>
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


void solve()
{
    int n, k;
    cin >> n >> k;
    vi l(n+1);
    vi r(n+1);
    mii mp;
    vi ansl1;
    vi ansl2;
    vi ansr1;
    vi ansr2;
    for(int i=1;i<=n;i++)
    {
        cin >> l[i];
        mp[l[i]]++;
        if (mp[l[i]] == 2)
        {
            ansl2.push_back(l[i]);
            ansl2.push_back(l[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin >> r[i];
        if (mp[r[i]] == 1)
        {
            ansl1.push_back(r[i]);
            ansr1.push_back(r[i]);
        }
        else if(mp[r[i]]==0)
        {
            ansr2.push_back(r[i]);
            ansr2.push_back(r[i]);
            mp[r[i]]+=2;
        }
    }
    sort(ansl1.begin(), ansl1.end());
    sort(ansr1.begin(), ansr1.end());

    int len = ansl2.size();
    for (int i = 0; i < 2 * k; i++)
    {
        if (i < len)
            cout << ansl2[i] << " ";
        else
            cout << ansl1[i - len] << " ";
    }
    cout << endl;
    for (int i = 0; i < 2 * k; i++)
    {
        if (i < len)
            cout << ansr2[i] << " ";
        else
            cout << ansr1[i - len] << " ";
    }
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