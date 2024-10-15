#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> segments;
    segments.reserve(m);
    vector<int> current_segment;

    for (int i = 0; i < n; ++i)
    {
        int r;
        cin >> r;
        if (r == 0)
        {
            if (!current_segment.empty())
            {
                segments.push_back(current_segment);
                current_segment.clear();
            }
        }
        else
        {
            current_segment.push_back(r);
        }
    }
    if (!current_segment.empty())
    {
        segments.push_back(current_segment);
    }

    // 确保有m个段（即有m个0），即使某些段为空
    while ((int)segments.size() < m)
    {
        segments.emplace_back(); // 添加空段
    }

    // 动态规划
    // dp[j] 表示分配了j个力量点后，通过的最大检查数量
    // 初始化所有dp为-1，表示未达状态
    // 初始状态：0个力量点，通过0个检查
    vector<int> dp_prev(m + 1, -1);
    dp_prev[0] = 0;

    // 处理每个段
    for (int seg = 0; seg < m; ++seg)
    {
        vector<int> dp_new(m + 1, -1);
        for (int j = 0; j <= m; ++j)
        {
            if (dp_prev[j] == -1)
            {
                continue;
            }
            // 当前段对应的第seg个0，将属性点分配给力量或智力
            // 分配给力量
            if (j + 1 <= m)
            {
                int new_j = j + 1;
                int assigned_i = seg - j; // 已分配给智力的点数
                // 分配给力量后，s = new_j, i = assigned_i
                // 计算当前段中可以通过的力量检查数量
                int pass_S = 0;
                for (auto &r : segments[seg])
                {
                    if (r < 0)
                    {
                        // 力量检查，要求s >= |r|
                        if (new_j >= abs(r))
                        {
                            pass_S += 1;
                        }
                    }
                    else
                    {
                        // 智力检查，要求i >= r
                        if (assigned_i >= r)
                        {
                            pass_S += 1;
                        }
                    }
                }
                if (pass_S != -1 && dp_prev[j] + pass_S > dp_new[new_j])
                {
                    dp_new[new_j] = dp_prev[j] + pass_S;
                }
            }
            // 分配给智力
            int new_j_i = j;                    // 分配给智力，j不变
            int assigned_i_new = (seg + 1) - j; // 分配给智力的点数增加1
            // 分配给智力后，s =j, i = assigned_i_new
            int pass_I = 0;
            for (auto &r : segments[seg])
            {
                if (r > 0)
                {
                    // 智力检查，要求i >= r
                    if (assigned_i_new >= r)
                    {
                        pass_I += 1;
                    }
                }
                else
                {
                    // 力量检查，要求s >= |r|
                    if (j >= abs(r))
                    {
                        pass_I += 1;
                    }
                }
            }
            if (pass_I != -1 && dp_prev[j] + pass_I > dp_new[j])
            {
                dp_new[j] = dp_prev[j] + pass_I;
            }
        }
        dp_prev = dp_new;
    }

    // 找到dp[j]中的最大值
    int max_passed = 0;
    for (int j = 0; j <= m; ++j)
    {
        if (dp_prev[j] > max_passed)
        {
            max_passed = dp_prev[j];
        }
    }

    cout << max_passed;
}
