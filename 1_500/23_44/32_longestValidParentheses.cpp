/* 32. 最长有效括号

给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号 子串 的长度。

左右括号匹配，即每个左括号都有对应的右括号将其闭合的字符串是格式正确的，比如 "(()())"。 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int len = s.size(), re = 0, left = 0, right = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == ')')
            {
                right++;
            }
            else
            {
                left++;
            }
            if (left == right)
            {
                re = max(re, 2 * left);
            }
            else if (right > left)
            {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] == ')')
            {
                right++;
            }
            else
            {
                left++;
            }
            if (left == right)
            {
                re = max(re, 2 * left);
            }
            else if (right < left)
            {
                left = right = 0;
            }

        }
        return re;
    }

    int dynamicProgramming(string s)
    {
        int len = s.size(), re = 0;
        vector<int> dp(len + 1);
        for (int i = 1; i < len; i++)
        {
            if (s[i] == '(')
            {
                continue;
            }
            if (s[i - 1] == '(')
            {
                dp[i + 1] = dp[i - 1] + 2;
                re = max(re, dp[i + 1]);
            }
            else
            {
                int index = i - dp[i] - 1;
                if (index >= 0 && s[index] == '(')
                {
                    dp[i + 1] = 2 + dp[i] + dp[i - 1 - dp[i]];
                    re = max(re, dp[i + 1]);
                }
            }
        }
        return re;
    }
};