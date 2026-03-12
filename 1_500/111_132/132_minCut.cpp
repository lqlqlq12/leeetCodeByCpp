/* 132. 分割回文串 II
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的 最少分割次数 。 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<bool>> isPalindrome;
    vector<int> dp;
    int minCut(string s)
    {
        int n = s.size();
        dp = vector<int>(n, INT_MAX);
        dp[0] = 0;
        isPalindrome = vector<vector<bool>>(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j <= i + 1; j++)
            {
                int left = i, right = j;
                while (left >= 0 && right < n && s[left] == s[right])
                {
                    isPalindrome[left][right] = true;
                    left--;
                    right++;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (isPalindrome[0][i])
            {
                dp[i] = 0;
                continue;
            }
            for (int j = 1; j <= i; j++)
            {
                if (isPalindrome[j][i])
                {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};