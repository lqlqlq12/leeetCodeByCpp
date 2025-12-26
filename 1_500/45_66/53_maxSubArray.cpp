/* 53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组是数组中的一个连续部分。

 */

#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return method_1(nums);
    }

    int method_1(vector<int> &nums)
    {
        int re = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > 0)
            {
                nums[i] += nums[i - 1];
            }
            re = max(re, nums[i]);
        }
        return re;
    }
};