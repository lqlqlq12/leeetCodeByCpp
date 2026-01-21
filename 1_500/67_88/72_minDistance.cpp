/* 72. 编辑距离
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符 */
#include <string>
using namespace std;
#include <vector>

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i + 1][j + 1] = dp[i][j];
                if (word1[i] != word2[j])
                {
                    dp[i + 1][j + 1] += 1;
                }
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1]) + 1);
            }
        }
        return dp[m][n];
    }
    int minDistance_2(string word1, string word2)
    {
        int m = word1.size(), n = word2.size(), last = 0;
        vector<int> dp(n + 1);

        for (int i = 0; i <= n; i++)
        {
            dp[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            last = dp[0];
            dp[0] = i + 1;
            for (int j = 0; j < n; j++)
            {
                int t = dp[j + 1];
                dp[j + 1] = last;
                if (word1[i] != word2[j])
                {
                    dp[j + 1] += 1;
                }
                dp[j + 1] = min(dp[j + 1], min(dp[j], t) + 1);
                last = t;
            }
        }
        return dp[n];
    }
};