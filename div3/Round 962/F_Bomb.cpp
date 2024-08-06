#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    int tot = 0;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        tot += (a[i] - 1) / b[i] + 1;
    }
    m = min(m, tot);
    int ans = 0;

    int l = 0, r = 1e6 + 5;
    auto check = [&](int x) -> bool
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] >= x)
                sum += (a[i] - x) / b[i] + 1;

        return sum >= m;
    };
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    l--;

    for (int i = 1; i <= n; i++)
    {
        int t = ((a[i] - l) / b[i] + 1);
        if (t <= 0 || a[i] < l)
            continue;

        if (a[i] - (t - 1) * b[i] == l)
            t--;

        ans += t * a[i] - (t * (t - 1) / 2 * b[i]);
        m -= t;
    }
    cout << ans + m * l << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}