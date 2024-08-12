#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <tuple>

#define ft first
#define sd second

#define yes cout << "yes\n"
#define no cout << "no\n"

#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define pb push_back
#define eb emplace_back

#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define sort1_all(x) sort(x.begin() + 1, x.end())

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"

// 红色
#define DEBUG1(x)                     \
    RED;                              \
    cout << #x << " : " << x << endl; \
    RESET;

// 绿色
#define DEBUG2(x)                     \
    GREEN;                            \
    cout << #x << " : " << x << endl; \
    RESET;

// 蓝色
#define DEBUG3(x)                     \
    BLUE;                             \
    cout << #x << " : " << x << endl; \
    RESET;

// 品红
#define DEBUG4(x)                     \
    MAGENTA;                          \
    cout << #x << " : " << x << endl; \
    RESET;

// 青色
#define DEBUG5(x)                     \
    CYAN;                             \
    cout << #x << " : " << x << endl; \
    RESET;

// 黄色
#define DEBUG6(x)                     \
    YELLOW;                           \
    cout << #x << " : " << x << endl; \
    RESET;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, ll> psl;

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pss> vpss;
typedef vector<ti3> vti3;
typedef vector<tl3> vtl3;
typedef vector<tld3> vtld3;

typedef vector<vi> vvi;
typedef vector<vl> vvl;

typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<pii> qpii;
typedef queue<pll> qpll;
typedef queue<psi> qpsi;
typedef queue<psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pll> pqpll;
typedef priority_queue<psi> pqpsl;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<ll, ll> mll;
typedef map<ll, bool> mlb;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<char, bool> mcb;
typedef map<string, int> msi;
typedef map<string, ll> msl;
typedef map<int, bool> mib;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;

#include <cstdio>

template <typename T>
inline T read()
{
    T x = 0;
    int y = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            y = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * y;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x >= 10)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

/*#####################################BEGIN#####################################*/
typedef long double ld;

const ld eps = 1e-10;

struct Point
{
    ld x, y;
    Point(ld x = 0, ld y = 0) : x(x), y(y) {};
};

typedef Point Vector;

Vector operator+(const Point &A, const Point &B)
{
    return Vector(A.x + B.x, A.y + B.y);
}
Vector operator-(const Point &A, const Point &B)
{
    return Vector(A.x - B.x, A.y - B.y);
}

Vector operator*(const Point &A, const ld &p)
{
    return Vector(A.x * p, A.y * p);
}

Vector operator/(const Point &A, const ld &p)
{
    return Vector(A.x / p, A.y / p);
}

bool operator<(const Point &A, const Point &B)
{
    return A.x < B.x || (A.x == B.x && A.y < B.y);
}

int Dcmp(ld x)
{
    if (fabs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}
bool operator==(const Point &A, const Point &B)
{
    return !Dcmp(A.x - B.x) && !Dcmp(A.y - B.y);
}

ld Polar_angle(Vector A)
{
    return atan2(A.y, A.x);
}

ld Dot(const Vector &A, const Vector &B)
{
    return A.x * B.x + A.y * B.y;
}

ld Cross(const Vector &A, const Vector &B)
{
    return A.x * B.y - A.y * B.x;
}

ld Length(const Vector &A)
{
    return sqrt(Dot(A, A));
}

ld Angle(const Vector &A, const Vector &B)
{
    return acos(Dot(A, B) / Length(A) / Length(B));
}

ld Area2(const Point &A, const Point &B, const Point &C)
{
    return Cross(B - A, C - A);
}

Vector Rotate(const Vector &A, ld rad)
{
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

Vector Normal(const Vector &A)
{
    ld L = Length(A);
    return Vector(-A.y / L, A.x / L);
}

Vector Format(const Vector &A)
{
    ld L = Length(A);
    return Vector(A.x / L, A.y / L);
}

bool ToLeftTest(const Point &A, const Point &B, const Point &C)
{
    return Cross(B - A, C - B) > 0;
}

ld Distance_point_to_point(const Point &A, const Point &B)
{
    return Length(A - B);
}

ld Distance_point_to_line(const Point &A, const Point &B, const Point &P)
{
    Vector v1 = B - A;
    Vector v2 = P - A;
    return fabs(Cross(v1, v2)) / Length(v1);
}

ld Distance_point_to_segment(const Point &A, const Point &B, const Point &P)
{
    if (A == B)
        return Length(P - A);
    Vector v1 = B - A;
    Vector v2 = P - A;
    Vector v3 = P - B;
    if (Dcmp(Dot(v1, v2)) < 0)
        return Length(v2);
    else if (Dcmp(Dot(v1, v3)) > 0)
        return Length(v3);
    else
        return fabs(Cross(v1, v2)) / Length(v1);
}

Point Get_line_projection(const Point &A, const Point &B, const Point &P)
{
    Vector v = B - A;
    return A + v * (Dot(v, P - A) / Dot(v, v));
}

bool onSegmet(const Point &pi, const Point &pj, const Point &Q)
{
    if ((Q.x - pi.x) * (pj.y - pi.y) == (Q.y - pi.y) * (pj.x - pi.x) && min(pi.x, pj.x) <= Q.x && Q.x <= max(pi.x, pj.x) && min(pi.y, pj.y) <= Q.y && Q.y <= max(pi.y, pj.y))
    {
        return true;
    }
    else
        return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<Point> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].x >> c[i].y;
    }
    Point A, B;
    cin >> A.x >> A.y >> B.x >> B.y;
    ld dist = Distance_point_to_point(A, B);
    for (int i = 0; i < n; i++)
    {
        ld d = Distance_point_to_point(c[i], B);
        if (dist >= d)
        {
            NO;
            return;
        }
    }
    YES;
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：