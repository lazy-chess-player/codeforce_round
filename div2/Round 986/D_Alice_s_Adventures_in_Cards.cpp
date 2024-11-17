#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        // 读取Queen, King, Jack的偏好顺序
        // p_q, p_k, p_j分别表示Queen, King, Jack对每个卡牌的偏好值
        vector<int> p_q(n + 1), p_k(n + 1), p_j(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p_q[i];
        for (int i = 1; i <= n; i++)
            cin >> p_k[i];
        for (int i = 1; i <= n; i++)
            cin >> p_j[i];

        // predecessor存储每个卡牌的前一个卡牌和通过哪个玩家交易得到
        // 使用pair<int, char>，第一个元素是前一个卡牌的编号，第二个元素是玩家标识（'q','k','j'）
        vector<pair<int, char>> predecessor(n + 1, {-1, ' '});

        // dp表示每个卡牌是否可以被到达
        // 由于我们只需要判断是否可达以及构建路径，不需要显式存储
        // 我们通过predecessor数组来间接表示
        // 初始化，卡牌1是起点
        // 初始化每个玩家的当前最大偏好值和对应的卡牌编号
        // max_p[0]对应Queen, max_p[1]对应King, max_p[2]对应Jack
        // c_p[0], c_p[1], c_p[2]分别记录对应玩家当前的卡牌编号
        vector<int> max_p(3, 0);
        vector<int> c_p(3, 0);
        // 初始化每个玩家的最大偏好值和卡牌编号为卡牌1
        max_p[0] = p_q[1];
        c_p[0] = 1;
        max_p[1] = p_k[1];
        c_p[1] = 1;
        max_p[2] = p_j[1];
        c_p[2] = 1;

        // 标记卡牌1为可达
        // 不需要显式标记，因为predecessor[1]保持为默认值
        // 开始从卡牌2到卡牌n逐一判断
        for (int x = 2; x <= n; x++)
        {
            bool can_reach = false;
            char used_player = ' ';
            int from_card = -1;
            // 检查每个玩家是否可以通过交易得到卡牌x
            for (int p = 0; p < 3; p++)
            {
                // 如果该玩家当前的最大偏好值大于卡牌x的偏好值
                if (max_p[p] > ((p == 0) ? p_q[x] : (p == 1) ? p_k[x]
                                                             : p_j[x]))
                {
                    // 前一个卡牌必须是可达的
                    // 因为c_p[p]是通过可达卡牌更新的，所以这里不用额外判断
                    can_reach = true;
                    from_card = c_p[p];
                    // 根据玩家编号选择对应的字符标识
                    if (p == 0)
                        used_player = 'q';
                    else if (p == 1)
                        used_player = 'k';
                    else
                        used_player = 'j';
                    break; // 只需要找到一个满足条件的玩家即可
                }
            }
            if (can_reach)
            {
                predecessor[x] = {from_card, used_player};
            }
            // 更新每个玩家的最大偏好值和对应的卡牌编号
            for (int p = 0; p < 3; p++)
            {
                int current_p;
                if (p == 0)
                    current_p = p_q[x];
                else if (p == 1)
                    current_p = p_k[x];
                else
                    current_p = p_j[x];
                if (current_p > max_p[p])
                {
                    max_p[p] = current_p;
                    c_p[p] = x;
                }
            }
        }

        // 检查卡牌n是否可达
        if (predecessor[n].first != -1 || n == 1)
        {
            // 可达，输出YES并重建路径
            cout << "YES\n";
            // 重建路径
            vector<pair<char, int>> path;
            int current = n;
            // 特殊情况，当n=1时，无需任何交易
            if (n != 1)
            {
                while (current != 1)
                {
                    auto [prev, player] = predecessor[current];
                    path.emplace_back(player, current);
                    current = prev;
                }
                // 输出交易次数
                cout << path.size() << "\n";
                // 反转路径以按交易顺序输出
                for (auto it = path.rbegin(); it != path.rend(); it++)
                {
                    cout << (char)tolower(it->first) << " " << it->second << "\n";
                }
            }
            else
            {
                // n=1时，无需任何交易
                cout << "0\n";
            }
        }
        else
        {
            // 不可达，输出NO
            cout << "NO\n";
        }
    }
}
