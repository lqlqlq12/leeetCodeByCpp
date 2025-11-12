#include <string>
#include <iostream>
#include <vector>
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
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] != '*')
                {
                    if (i > 0 && (p[j - 1] == '.' || s[i - 1] == p[j - 1]))
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
                else
                {
                    if (dp[i][j - 2])
                    {
                        dp[i][j] = true;
                        continue;
                    }
                    if (i > 0 && (p[j - 2] == '.' || s[i - 1] == p[j - 2]))
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }

    bool isMatch_version2(string s, string p)
    {
        int m = s.size(), n = p.size(), sIndex = 0, pIndex = 0;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int j = 1; j < n; j += 2)
        {
            if (p[j] == '*')
            {
                dp[0][j + 1] = true;
            }
            else
            {
                break;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                char target = s[i - 1];
                char pattern = p[j - 1];
                if (pattern == target)
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pattern == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pattern == '*')
                {
                    if (p[j - 2] == '.' || p[j - 2] == target)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    if (!dp[i][j])
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    Solution sol;
    cout << sol.isMatch("mississippi", "mis*is*p*.");
    return 0;
}