/* 120. 三角形最小路径和
给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。 */

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size(), re = INT_MAX;
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        for (int i = 2; i <= n; i++)
        {
            dp[i - 1] = triangle[i - 1][i - 1] + dp[i - 2];
            for (int j = i - 2; j > 0; j--)
            {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i - 1][j];
            }
            dp[0] += triangle[i - 1][0];
        }
        for (int i = 0; i < n; i++)
        {
            re = min(re, dp[i]);
        }
        return re;
    }
};

int main(){
    vector<vector<int>> t {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution sol;
    sol.minimumTotal(t);
}