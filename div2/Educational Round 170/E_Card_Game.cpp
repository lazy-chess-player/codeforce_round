#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int MAX = 250000 + 10;

// 快速幂
ll power_pow(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 预计算阶乘和逆阶乘
ll fact[MAX], inv_fact[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // 预计算阶乘
    fact[0] = 1;
    for (int i = 1; i <= n * m; i++)
        fact[i] = fact[i - 1] * i % MOD;
    // 预计算逆阶乘
    inv_fact[n * m] = power_pow(fact[n * m], MOD - 2);
    for (int i = n * m - 1; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    // 组合数函数
    auto comb = [&](int a, int b) -> ll
    {
        if (a < 0 || b < 0 || a < b)
            return 0;
        return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
    };
    ll total = 0;
    // 根据题意，k从ceil(m/2)到m
    int min_k = (m + 1) / 2;
    for (int k = min_k; k <= m; k++)
    {
        // 计算 C(m,k) - C(m,k-1)
        ll cmk = comb(m, k);
        ll cmk1 = comb(m, k - 1);
        ll num_S1 = (cmk - cmk1) % MOD;
        if (num_S1 < 0)
            num_S1 += MOD;
        // 计算 R和R'
        ll N = n * m;
        if (N % 2 != 0)
            continue; // 如果总数不是偶数，跳过
        ll half = N / 2;
        ll R = half - k;
        int n_prime = n - 1;
        ll R_prime = 0;
        if (n > 1)
        {
            R_prime = R - (n_prime) * (m - k);
        }
        if (n == 1)
        {
            // 当n=1时，只需R ==0
            if (R != 0)
            {
                continue;
            }
            // 当n=1且R==0时，ways_k =1
            total = (total + num_S1) % MOD;
            continue;
        }
        // 对于n >1
        if (R_prime < 0 || R_prime > n_prime * k)
        {
            continue;
        }
        // 计算包容排斥
        ll ways_k = 0;
        for (int j = 0; j <= n_prime; j++)
        {
            // 计算 R' - j*(k+1)
            ll term = R_prime - (ll)j * (k + 1);
            if (term < 0)
                continue;
            // 计算C(n',j)
            ll Cnj = comb(n_prime, j);
            // 计算C(term + n' -1, n' -1)
            ll Csum = comb(term + n_prime - 1, n_prime - 1);
            // 计算 (-1)^j * C(n',j) * Csum
            if (j % 2)
            {
                ways_k = (ways_k - Cnj * Csum % MOD + MOD) % MOD;
            }
            else
            {
                ways_k = (ways_k + Cnj * Csum % MOD) % MOD;
            }
        }
        total = (total + num_S1 * ways_k % MOD) % MOD;
    }
    cout << total;
}
