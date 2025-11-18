/* 18. 四数之和

给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> re;
        for (int i = 0; i < len - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            if ((long)nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target)
                continue;
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 1] > target)
                break;
            for (int j = i + 1; j < len - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                long pre = nums[i] + nums[j];
                if (pre + nums[len - 1] + nums[len - 2] < target)
                    continue;
                if (pre + nums[j + 1] + nums[j + 2] > target)
                {
                    break;
                }
                int k = j + 1, l = len - 1;
                while (k < l)
                {
                    while (k < l && pre + nums[k] + nums[l] < target)
                    {
                        k++;
                    }
                    if (k == l)
                        break;
                    if (pre + nums[k] + nums[l] == target)
                    {
                        re.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    while (k < l && pre + nums[k] + nums[l] > target)
                    {
                        l--;
                    }
                    if (k >= l)
                        break;
                    if (pre + nums[k] + nums[l] == target)
                    {
                        re.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }
        return re;
    }
};