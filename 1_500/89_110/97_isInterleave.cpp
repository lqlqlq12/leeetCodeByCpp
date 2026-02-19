/* 97. 交错字符串
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size(), t = s3.size();
        if (m + n != t)
        {
            return false;
        }
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int index = i + j - 1;
                if (i > 0 && dp[i - 1][j] && s1[i - 1] == s3[index])
                {
                    dp[i][j] = true;
                }
                if (!dp[i][j] && j > 0 && dp[i][j - 1] && s2[j - 1] == s3[index])
                {
                    dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }

    bool optimize(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size(), t = s3.size();
        if (m + n != t)
        {
            return false;
        }
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                int index = i + j - 1;
                bool flag = false;
                if (i > 0 && dp[j] && s1[i - 1] == s3[index])
                {
                    flag = true;
                }
                if (j > 0 && dp[j - 1] && s2[j - 1] == s3[index])
                {
                    flag = true;
                }
                dp[j] = flag;
            }
        }
        return dp[n];
    }
};