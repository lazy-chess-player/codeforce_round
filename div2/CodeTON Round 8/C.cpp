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

#define RESET   std::cout<<"\033[0m"
#define BLACK   std::cout<<"\033[30m"      
#define RED     std::cout<<"\033[31m"
#define GREEN   std::cout<<"\033[32m"
#define YELLOW  std::cout<<"\033[33m"
#define BLUE    std::cout<<"\033[34m"
#define MAGENTA std::cout<<"\033[35m"
#define CYAN    std::cout<<"\033[36m"
#define WHITE   std::cout<<"\033[37m"


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

const int N = 2e5 + 10;

void solve()
{
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    int m = y;
    vi a(x);
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }
    if (x + y == n)
    {
        cout << n - 2 << endl;
        return;
    }
    sort(a.begin(), a.end());
    a.push_back(a[0] + n);
    int cnt = 0;
    vi diff;
    for (int i = 1;i <= x; i++)
    {
        int d = a[i] - a[i - 1] - 1;
        if (d == 1)
            cnt++;
        if (d > 1)
            diff.push_back(d);
    }
    sort(diff.begin(), diff.end(),greater<int>());
    for (int i = 0; i < diff.size() && y; i++)
    {
        if (diff[i] % 2 && y >= (diff[i] / 2))
        {
            cnt += (diff[i] / 2) * 2;
            y -= (diff[i] / 2);
            diff[i] = 0;
        }
    }
    sort(diff.begin(), diff.end(), greater<int>());
    for (int i = 0; i < diff.size() && y; i++)
    {
        if (y >= (diff[i] / 2))
        {
            cnt += (diff[i] / 2);
            y -= (diff[i] / 2);
            diff[i] = 0;
        }
    }
    cnt += (x + m - 2);
    cout << cnt << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
