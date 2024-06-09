#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

void solve(ll t, vector<pair<ll, vector<ll>>> &test_cases)
{
    for (ll i = 0; i < t; ++i)
    {
        ll n = test_cases[i].first;
        vector<ll> &k = test_cases[i].second;

        long long total_product = 1;
        for (ll j = 0; j < n; ++j)
        {
            total_product *= k[j];
        }

        vector<long long> bets(n);
        for (ll j = 0; j < n; ++j)
        {
            bets[j] = total_product / k[j];
        }

        long long total_bet = accumulate(bets.begin(), bets.end(), 0LL);
        bool valid = true;
        for (ll j = 0; j < n; ++j)
        {
            if (k[j] * bets[j] <= total_bet)
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            for (ll j = 0; j < n; ++j)
            {
                cout << bets[j] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    vector<pair<ll, vector<ll>>> test_cases(t);
    for (ll i = 0; i < t; ++i)
    {
        ll n;
        cin >> n;
        vector<ll> k(n);
        for (ll j = 0; j < n; ++j)
        {
            cin >> k[j];
        }
        test_cases[i] = make_pair(n, k);
    }

    solve(t, test_cases);
    return 0;
}
