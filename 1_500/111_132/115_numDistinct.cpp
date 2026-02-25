/* 115. 不同的子序列
给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。

测试用例保证结果在 32 位有符号整数范围内。 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = t.size(), n = s.size();
        vector<vector<unsigned long long>> dp (m+1,vector<unsigned long long>(n+1));
        fill(dp[0].begin(),dp[0].end(),1);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i+1][j+1] = dp[i+1][j];
                if (t[i] == s[j]) {
                    dp[i+1][j+1] += dp[i][j];
                }
            }
        }
        return dp[m][n];
    }
};