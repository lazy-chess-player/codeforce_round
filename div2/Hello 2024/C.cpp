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
#include <bitset>
#include <cmath>

#define endl '\n'

#define ft first
#define sd second

#define yes std::cout<<"Yes\n";
#define no std::cout<<"No\n";


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


void cinv(vi vec, int n) { for (int i = 1; i <= (n); i++)cin >> (vec)[i]; }
void rcinv(vi vec, int n) { for (int i = (n); i >= 1; i--)cin >> (vec)[i]; }
void coutv(vi vec, int n) { for (int i = 1; i <= (n); i++)cout << (vec)[i] << " "; cout << '\n'; }
void rcoutv(vi vec, int n) { for (int i = (n); i >= 1; i--)cout << (vec)[i] << " "; cout << '\n'; }

// 一开始有两个盒子，每个盒子可以装下比自己小的一个盒子，装下比自己小的盒子之后，
// 容量就会变小，如果两个盒子都装不下，我们就可以花费代价去换一个任意大的盒子，
// 无论多大，花费的代价都是1。现在有一堆盒子等我们装起来，把所有盒子装下的代价
// 是多少。我们可以一开始看作拥有两个无限大容量的盒子，在装盒子的过程中，如果待
// 装的盒子比现有的两个盒子容量都小，那么肯定是用更小的那个盒子去装，如果用更大
// 的盒子去装，那么浪费的容量就会更大；如果待装的盒子比小盒子大，比大盒子小，那
// 么肯定装进大盒子里，没必要花费代价去换一个盒子；如果待装的盒子比两个盒子都大，
// 那肯定是换掉更小的那个盒子，因为换多大的盒子的代价都一样，既然花的钱一样，肯
// 定是把小的换了留大的。
void solve()
{
    ll n; cin >> n;
    int minbox=INT32_MAX;
    int maxbox=INT32_MAX;
    int now;
    int cost=0;
    for(int i=0;i<n;i++)
    {
        cin>>now;
        if(minbox>maxbox)// 只需要知道小盒子和大盒子的容量分别是多少就行
            swap(minbox,maxbox);
        if(now<=minbox)// 比小盒子更小，装进小盒子里
            minbox=now;
        else if(now>maxbox)// 比大盒子更大，花费1代价换掉小盒子
        {
            cost++;
            minbox=now;
        }
        else// 比大盒子小且比小盒子大，装进大盒子
            maxbox=now;
    }
    cout<<cost<<endl;
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