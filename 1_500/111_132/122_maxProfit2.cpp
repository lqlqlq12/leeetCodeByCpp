/* 122. 买卖股票的最佳时机 II
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。然而，你可以在 同一天 多次买卖该股票，但要确保你持有的股票不超过一股。

返回 你能获得的 最大 利润 。 */
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(), x = 0, y = -prices[0];
        for (int i = 1; i < n; i++)
        {
            int t = x;
            x = max(x, y + prices[i]);
            y = max(y, t - prices[i]);
        }
        return max(x, y);
    }
};