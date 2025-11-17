/* 14. 最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。 */
using namespace std;
#include <vector>
#include <string>

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int len = strs.size();
        if (len == 1)
        {
            return strs[0];
        }
        string re = strs[0];
        for (int i = 1; i < len; i++)
        {
            int minLen = min(re.size(), strs[i].size());
            int index = 0;
            for (; index < minLen; index++)
            {
                if (re[index] != strs[i][index])
                {
                    break;
                }
            }
            if (index == 0)
            {
                return "";
            }
            else if (index < re.size())
            {
                re = re.substr(0, index);
            }
        }
        return re;
    }
};