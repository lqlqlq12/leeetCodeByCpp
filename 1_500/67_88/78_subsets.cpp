/* 78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> re;
        vector<int> list(0);
        re.emplace_back(list);
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            int tSize = re.size();
            for (int j = 0; j < tSize; j++)
            {
                vector<int> tList = re[j];
                tList.push_back(nums[i]);
                re.emplace_back(tList);
            }
        }
        return re;
    }
};