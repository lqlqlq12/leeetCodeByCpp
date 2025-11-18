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
        int len = nums.size();
        for (int i = 0; i < len - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = len - 1,target = -nums[i];
            while (j<k)
            {
                if(nums[j]+nums[k]==target){
                    re.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[j]+nums[k]<target){
                    j++;
                }
                else{
                    k--;
                }
                while(j<k&&nums[j]==nums[j-1])j++;
                while(j<k&&nums[k]==nums[k+1])k--;
            }
        }
        return re;
    }
};