/* 15. 三数之和

给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> re;
        int len = nums.size(), k = len - 1;
        for (int i = 0; i < k - 1; i++)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                for (int j = i + 1; j < k; j++)
                {
                    if (nums[j] == nums[i] || nums[j] != nums[j - 1])
                    {
                        while (j < k && nums[i] + nums[j] + nums[k] > 0)
                        {
                            k--;
                        }
                        if (nums[i] + nums[j] + nums[k] == 0)
                        {
                            re.push_back({nums[i], nums[j], nums[k]});
                        }
                    }
                }
            }
        }
        return re;
    }
};