/* 84. 柱状图中最大的矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。 */
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size(), re = 0;
        vector<int> left(n), right(n, n);
        stack<int> sta;
        sta.push(-1);
        for (int i = 0; i < n; i++)
        {
            while (sta.top() != -1 && heights[sta.top()] >= heights[i])
            {
                right[sta.top()] = i;
                sta.pop();
            }
            left[i] = sta.top();
            sta.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            re = max(re, heights[i] * (right[i] - left[i] - 1));
        }
        return re;
    }
};