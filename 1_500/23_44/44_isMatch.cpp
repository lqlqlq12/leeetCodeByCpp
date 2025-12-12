/* 44. 通配符匹配
给你一个输入字符串 (s) 和一个字符模式 (p) ，请你实现一个支持 '?' 和 '*' 匹配规则的通配符匹配：
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符序列（包括空字符序列）。
判定匹配成功的充要条件是：字符模式必须能够 完全匹配 输入字符串（而不是部分匹配）。 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        for (int i = 0; i < n; i++)
        {
            if (p[i] == '*')
            {
                dp[i + 1][0] = true;
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            char pattern = p[i];
            for (int j = 0; j < m; j++)
            {
                if (pattern == '?' || pattern == '*' || p[i] == s[j])
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                if (dp[i + 1][j + 1])
                {
                    continue;
                }
                if (pattern == '*')
                {
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
                }
            }
        }
        return dp[n][m];
    }

    bool isMatch_sec(string s, string p)
    {
        int sLen = s.size(), pLen = p.size(), pIndex = 0, sIndex = 0;
        while (sIndex < sLen && pIndex < pLen)
        {
            while (pIndex < pLen && p[pIndex] == '*')
            {
                pIndex++;
            }
            int originP = pIndex, originS = sIndex;
            while (pIndex < pLen && sIndex < sLen && p[pIndex] != '*')
            {
                if (p[pIndex] == s[sIndex] || p[pIndex] == '?')
                {
                    pIndex++;
                    sIndex++;
                }
                else
                {
                    pIndex = originP;
                    sIndex = ++originS;
                }
            }
        }
        while (pIndex < pLen && p[pIndex] == '*')
        {
            pIndex++;
        }
        return pIndex == pLen;
    }
};

int main()
{
    Solution sol;
    sol.isMatch("", "**");
    return 0;
}