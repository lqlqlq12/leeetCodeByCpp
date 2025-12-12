/* 47. 全排列 II
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 */


#include <vector>
using namespace std;

class Solution {
public:


    vector<int> array;
    vector<bool> isUsed;
    vector<vector<int>> re;

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        array = nums;
        isUsed = vector<bool>(nums.size());
        vector<int> temp;
        dfs(temp);
        return re;
    }

    void dfs(vector<int> cur)
    {
        if (cur.size() == array.size())
        {
            re.push_back(vector<int>(cur));
            return;
        }
        for (int i = 0; i < array.size(); i++)
        {
            if (!isUsed[i])
            {
                isUsed[i] = true;
                cur.push_back(array[i]);
                dfs(cur);
                isUsed[i] = false;
                cur.pop_back();
            }
        }
    }
};