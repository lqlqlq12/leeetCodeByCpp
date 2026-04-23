/* 139. 单词拆分
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。 */

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int minLen = INT_MAX, maxLen = 0, len = s.size();
        unordered_set<string> wordSet;
        for (auto word : wordDict)
        {
            minLen = min(minLen, (int)word.length());
            maxLen = max(maxLen, (int)word.length());
            wordSet.insert(word);
        }
        vector<bool> dp(len);
        for (int i = minLen - 1; i < len; i++)
        {
            if (wordSet.find(s.substr(0, i + 1)) != wordSet.end())
            {
                dp[i] = true;
                continue;
            }
            for (int start = i - minLen + 1; start > 0 && start > i - maxLen; start--)
            {
                if (dp[start - 1] && wordSet.find(s.substr(start, i - start + 1)) != wordSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len - 1];
    }
};