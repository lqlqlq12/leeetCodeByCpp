/* 46. 全排列

给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。 */

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> array;
    vector<bool> isUsed;
    vector<vector<int>> re;

    vector<vector<int>> permute(vector<int> &nums)
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