#include <bits/stdc++.h>
using namespace std;

// 定义一个结构体来存储牛奶的获取日和剩余量
struct Milk
{
    int day;          // 获取的日子
    long long amount; // 剩余的牛奶量

    // 重载小于运算符，使优先队列按照day降序排列（最鲜的牛奶在顶部）
    bool operator<(const Milk &other) const
    {
        return day < other.day;
    }
};

int main()
{
    // 优化输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // 读取测试用例数量
    while (t--)
    {
        int n;
        long long m, k;
        cin >> n >> m >> k; // 读取每个测试用例的n, m, k

        // 读取n个牛奶获取记录，并存储在一个向量中
        vector<pair<int, long long>> entries(n);
        for (int i = 0; i < n; i++)
        {
            cin >> entries[i].first >> entries[i].second;
        }

        // 使用优先队列（最大堆）来存储当前可饮用的牛奶，按照day降序排列
        priority_queue<Milk> pq;

        int idx = 0;               // 当前处理的记录索引
        int satisfaction_days = 0; // 满意的天数

        // 如果有记录，初始化当前日为第一个获取牛奶的日子
        if (n > 0)
        {
            int current_day = entries[0].first;
            // 计算最后一个可能有牛奶的日子
            int last_day = entries[n - 1].first + k - 1;

            // 使用一个循环模拟每天的饮用过程
            while (current_day <= last_day || !pq.empty())
            {
                // 将所有在current_day获取的牛奶加入优先队列
                while (idx < n && entries[idx].first == current_day)
                {
                    Milk milk;
                    milk.day = entries[idx].first;
                    milk.amount = entries[idx].second;
                    pq.emplace(milk);
                    idx++;
                }

                // 移除所有已经过期的牛奶（当前天大于d_i + k -1）
                while (!pq.empty() && (pq.top().day + k - 1) < current_day)
                {
                    pq.pop();
                }

                // 如果还有牛奶可以饮用
                if (!pq.empty())
                {
                    long long need = m;        // 今天需要饮用的牛奶量
                    long long total_drink = 0; // 今天实际饮用的牛奶量

                    // 使用一个临时容器来存储更新后的牛奶
                    // 这样可以避免在优先队列中直接修改
                    vector<Milk> temp_milks;

                    // 循环饮用牛奶，直到满足需求或没有牛奶可饮用
                    while (need > 0 && !pq.empty())
                    {
                        Milk top = pq.top();
                        pq.pop();

                        if (top.amount >= need)
                        {
                            total_drink += need;
                            top.amount -= need;
                            need = 0;
                            if (top.amount > 0)
                            {
                                temp_milks.emplace_back(top);
                            }
                        }
                        else
                        {
                            total_drink += top.amount;
                            need -= top.amount;
                            // 不需要重新加入，因为已经全部饮用了
                        }
                    }

                    // 将剩余的牛奶重新加入优先队列
                    for (auto &milk : temp_milks)
                    {
                        pq.emplace(milk);
                    }

                    // 如果今天饮用了至少m品脱牛奶，计为满意的一天
                    if (total_drink >= m)
                    {
                        satisfaction_days++;
                    }
                }
                // 移动到下一天
                current_day++;
            }
        }
        cout << satisfaction_days << "\n"; // 输出满意的天数
    }
}
