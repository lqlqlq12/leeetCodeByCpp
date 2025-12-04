/* 41. 缺失的第一个正数

给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (nums[i] <= 0)
            {
                nums[i] = len + 1;
            }
        }

        for (int i = 0; i < len; i++)
        {
            int x = abs(nums[i]);
            if (x < len + 1 && x > 0)
            {
                nums[x - 1] = -abs(nums[x - 1]);
            }
        }
        for (int i = 0; i < len; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }
        return len + 1;
    }
};