/* 140. 单词拆分 II
给定一个字符串 s 和一个字符串字典 wordDict ，在字符串 s 中增加空格来构建一个句子，使得句子中所有的单词都在词典中。以任意顺序 返回所有这些可能的句子。

注意：词典中的同一个单词可能在分段中被重复使用多次。 */
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
private:
    int maxLen, minLen;
    unordered_set<string> wordSet;
    vector<string> re;
    string s;

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        maxLen = 0, minLen = INT_MAX;
        for (auto word : wordDict)
        {
            wordSet.insert(word);
            maxLen = max(maxLen, (int)word.size());
            minLen = min(minLen, (int)word.size());
        }
        this->s = s;
        vector<string> temp;
        dfs(temp, 0);
        return re;
    }

    void dfs(vector<string> &curList, int index)
    {
        if (index == s.size())
        {
            string ans;
            for (auto word : curList)
            {
                ans += (word + " ");
            }
            ans.pop_back();
            re.push_back(ans);
            return;
        }
        for (int i = minLen; i <= maxLen && index + i <= s.size(); i++)
        {
            string word = s.substr(index, i);
            if (wordSet.find(word) != wordSet.end())
            {
                curList.push_back(word);
                dfs(curList, index + i);
                curList.pop_back();
            }
        }
    }
};