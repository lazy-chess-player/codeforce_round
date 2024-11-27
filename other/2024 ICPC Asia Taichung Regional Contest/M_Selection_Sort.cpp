#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> s(n);
    for (auto &x : s)
        cin >> x;

    // 1. 计算前缀的最大值
    // max_prefix[i] 表示前 i 个元素中的最大值
    // max_prefix[0] 初始化为 INT32_MIN，表示空前缀
    vector<int> max_prefix(n + 1, INT32_MIN);
    for (int i = 1; i <= n; i++)
    {
        max_prefix[i] = max(max_prefix[i - 1], s[i - 1]);
    }

    // 2. 计算后缀的最小值
    // min_suffix[j] 表示后 j 个元素中的最小值
    // min_suffix[0] 初始化为 INT32_MAX，表示空后缀
    vector<int> min_suffix(n + 1, INT32_MAX);
    for (int j = 1; j <= n; j++)
    {
        min_suffix[j] = min(min_suffix[j - 1], s[n - j]);
    }

    // 3. 初始化最小成本为排序整个数组的成本 n^2
    ll min_cost = (ll)n * n;

    // 4. 遍历所有可能的前缀长度 i
    for (int i = 0; i <= n; i++)
    {
        // 情况1：非重叠操作，后缀长度 j = n - i
        int j_eq = n - i;
        if (j_eq >= 0 && j_eq <= n)
        {
            // 检查前缀排序和后缀排序是否满足连接条件
            if (max_prefix[i] <= min_suffix[j_eq])
            {
                ll cost = (ll)i * i + (ll)j_eq * j_eq;
                if (cost < min_cost)
                {
                    min_cost = cost;
                }
            }
        }

        // 情况2：重叠操作，后缀长度 j = n - i +1
        int j_min = n - i + 1;
        if (j_min >= 1 && j_min <= n)
        {
            // 检查前缀排序和后缀排序是否满足连接条件
            if (max_prefix[i] <= min_suffix[j_min])
            {
                ll cost = (ll)i * i + (ll)j_min * j_min;
                if (cost < min_cost)
                {
                    min_cost = cost;
                }
            }
        }
    }

    cout << min_cost;

    return 0;
}
