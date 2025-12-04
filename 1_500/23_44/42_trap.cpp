/* 42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 */

#include <vector>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int len = height.size(), re = 0;
        vector<int> left(len);
        vector<int> right(len);
        for (int i = 1, highest = height[0]; i < len; i++)
        {
            if (height[i] <= highest)
            {
                left[i] = highest;
            }
            else
            {
                highest = height[i];
                left[i] = height[i];
            }
        }

        for (int i = len - 2, highest = height[len - 1]; i >= 0; i--)
        {
            if (height[i] <= highest)
            {
                right[i] = highest;
            }
            else
            {
                highest = height[i];
                right[i] = height[i];
            }
        }
        for (int i = 1; i < len - 1; i++)
        {
            int cur = height[i], leftMax = left[i], rightMax = right[i];
            if (leftMax > cur && rightMax > cur)
            {
                int minVal = min(leftMax, rightMax);
                re += (minVal - cur);
            }
        }
        return re;
    }
};