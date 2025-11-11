#include <string>
#include <iostream>
using namespace std;
/* 10. 正则表达式匹配

给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s 的，而不是部分字符串。

 */

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int sLen = s.size(), pLen = p.size(), sIndex = 0, pIndex = 0;
        for (; sIndex < sLen && pIndex < pLen;)
        {
            char target = s[sIndex];
            char pattern = p[pIndex];
            if (target == pattern || pattern == '.')
            {
                sIndex++;
                pIndex++;
            }
            else if (pattern == '*')
            {
                if (pIndex > 0 && (p[pIndex - 1] == target || p[pIndex - 1] == '.'))
                {
                    sIndex++;
                }
                else
                {
                    pIndex++;
                }
            }
            else if (pIndex < pLen - 1 && p[pIndex + 1] == '*')
            {
                pIndex++;
            }
            else
            {
                return false;
            }
        }
        for (; pIndex < pLen; pIndex++)
        {
            if (p[pIndex] == '*')
            {
                continue;
            }
            else if (pIndex < pLen - 1 && p[pIndex + 1] == '*')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return sIndex == sLen;
    }
};

int main()
{
    Solution sol;
    cout << sol.isMatch("aa", "a.");
    return 0;
}