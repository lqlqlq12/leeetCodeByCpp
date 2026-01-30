/* 80. 删除有序数组中的重复项 II
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。 */
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int result = 2, len = nums.size();
        if (len <= 2)
        {
            return len;
        }
        for (int i = 2; i < len; i++)
        {
            if (nums[i] == nums[result - 2])
            {
                continue;
            }
            nums[result++] = nums[i];
        }
        return result;
    }
};