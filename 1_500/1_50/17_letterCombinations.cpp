/* 17. 电话号码的字母组合

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 */

#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> alphas{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits)
    {
        // return bfs(0, digits);
        return bfs_2(0, digits, {""});
    }

    // 0ms
    vector<string> bfs(int index, string digits)
    {
        vector<string> re;
        if (index == digits.size())
        {
            return {""};
        }
        vector<string> next = bfs(index + 1, digits);
        string cs = alphas[digits[index] - '2'];
        for (size_t i = 0; i < cs.size(); i++)
        {
            char c = cs[i];
            for (size_t j = 0; j < next.size(); j++)
            {
                re.push_back(c + next[j]);
            }
        }
        return re;
    }

    vector<string> bfs_2(int index, string digits, vector<string> temp)
    {
        if (index == digits.size())
        {
            return temp;
        }
        vector<string> nextTemp;
        string cs = alphas[digits[index] - '2'];
        for (size_t i = 0; i < cs.size(); i++)
        {
            char c = cs[i];
            for (size_t j = 0; j < temp.size(); j++)
            {
                nextTemp.push_back(temp[j] + c);
            }
        }
        return bfs_2(index + 1, digits, nextTemp);
    }
};