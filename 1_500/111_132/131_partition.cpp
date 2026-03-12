/* 131. 分割回文串
给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string s;
    vector<vector<string>> re;
    vector<vector<bool>> dp;
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        this->s = s;
        dp = vector<vector<bool>>(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j <= i + 1; j++)
            {
                int left = i, right = j;
                while (left >= 0 && right < n && s[left] == s[right])
                {
                    dp[left][right] = true;
                    left--;
                    right++;
                }
            }
        }
        vector<string> temp;
        dfs(0, temp);
        return re;
    }

    void dfs(int index, vector<string> &curList)
    {
        if (index == s.size())
        {
            re.push_back(curList);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (dp[index][i])
            {
                curList.push_back(s.substr(index, i - index + 1));
                dfs(i + 1, curList);
                curList.pop_back();
            }
        }
    }
};