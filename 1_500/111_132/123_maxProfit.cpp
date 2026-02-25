/* 123. 买卖股票的最佳时机 III
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 */
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> arr(5);
        int n = prices.size();
        arr[1] = -prices[0];
        arr[3] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            arr[4] = max(arr[4], arr[3] + prices[i]);
            arr[3] = max(arr[3], arr[2] - prices[i]);
            arr[2] = max(arr[2], arr[1] + prices[i]);
            arr[1] = max(arr[1], -prices[i]);
        }
        return *max_element(arr.begin(), arr.end());
    }
};