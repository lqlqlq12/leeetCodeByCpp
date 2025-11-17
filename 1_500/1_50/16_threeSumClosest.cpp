/* 16. 最接近的三数之和

给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

 */

#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int re = nums[0] + nums[1] + nums[2];
        re = updateMinVal(target, re, nums[n - 3] + nums[n - 2] + nums[n - 1]);
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int tar = target - nums[i];
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                while (j < k && nums[j] + nums[k] > tar)
                {
                    k--;
                }
                if (k < n - 1)
                    re = updateMinVal(target, re, nums[i] + nums[j] + nums[k + 1]);
                if (j == k)
                    break;
                if (nums[j] + nums[k] == tar)
                {
                    return target;
                }
                re = updateMinVal(target, re, nums[i] + nums[j] + nums[k]);
                while (j < k - 1 && nums[k] == nums[k - 1] == nums[k - 2])
                {
                    k--;
                }

                while (j < k && nums[j] + nums[k] < tar)
                {
                    j++;
                }
                if (j > i + 1)
                    re = updateMinVal(target, re, nums[i] + nums[j - 1] + nums[k]);
                if (j == k)
                    break;
                if (nums[j] + nums[k] == tar)
                {
                    return target;
                }
                re = updateMinVal(target, re, nums[j] + nums[j] + nums[k]);
                while (j < k - 1 && nums[j] == nums[j + 1] == nums[j + 2])
                {
                    j++;
                }
            }
        }
        return re;
    }

    int updateMinVal(int target, int oldVal, int newVal)
    {
        int oldAbs = oldVal > target ? oldVal - target : target - oldVal;
        int newAbs = newVal > target ? newVal - target : target - newVal;
        return oldAbs < newAbs ? oldVal : newVal;
    }

    int simplyVersion(vector<int> &nums, int target)
    {
        int n = nums.size(), min = INT_MAX, re = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right], diff = abs(sum + nums[i] - target);
                if (diff == 0)
                {
                    return target;
                }
                else if (sum + nums[i] > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
                if (min > diff)
                {
                    min = diff;
                    re = sum + nums[i];
                }
            }
        }
        return re;
    }
};

int main()
{
    Solution sol;
    vector<int> ve{-1000, -5, -5, -5, -5, -5, -5, -1, -1, -1};
    sol.threeSumClosest(ve, -8);
    return 0;
}