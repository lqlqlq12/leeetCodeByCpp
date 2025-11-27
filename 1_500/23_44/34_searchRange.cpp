/* 34. 在排序数组中查找元素的第一个和最后一个位置

给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int len = nums.size(), left = 0, right = len - 1, start = -1, end = -1;
        vector<int> re;
        if (len == 1 && nums[0] != target)
        {
            re.push_back(-1);
            re.push_back(-1);
            return re;
        }
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
            {
                start = mid;
                right = mid - 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (start == -1)
        {
            re.push_back(-1);
            re.push_back(-1);
            return re;
        }
        left = 0, right = len - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
            {
                end = mid;
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        re.push_back(start);
        re.push_back(end);
        return re;
    }
};