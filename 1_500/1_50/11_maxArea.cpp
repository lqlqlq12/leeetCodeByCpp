#include <vector>
#include <algorithm>
using namespace std;

/* 11. 盛最多水的容器

给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器 */

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int len = height.size(), left = 0, right = len - 1, maxArea = 0, width = len - 1;
        while (left < right)
        {
            int minHeight = min(height[left], height[right]);
            maxArea = max(maxArea, minHeight * width);
            width--;
            if (minHeight == height[left])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<int> arr{1, 8, 6, 2, 5, 4, 8, 3, 7};
    sol.maxArea(arr);
    return 0;
}