#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve() 
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    int l, r, k;
    while (q--)
    {
        cin >> l >> r >> k;
        ll sum = a[n] - a[r] + a[l - 1] + (l + r - 1) * k;
        if (sum & 1) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}

int main() 
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
