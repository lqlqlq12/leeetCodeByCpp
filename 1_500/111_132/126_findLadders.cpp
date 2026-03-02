/* 126. 单词接龙 II
按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，一个表示此过程的 转换序列 是形式上像 beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：

每对相邻的单词之间仅有单个字母不同。
转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 不必是字典 wordList 中的单词。
sk == endWord
给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。请你找出并返回所有从 beginWord 到 endWord 的 最短转换序列 ，如果不存在这样的转换序列，返回一个空列表。每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回。 */

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<string>> re;
    unordered_map<string, vector<string>> map;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        if (!buildGraph(beginWord, endWord, wordList))
        {
            return re;
        }
        vector<string> temp;
        temp.push_back(endWord);
        dfsBuildList(beginWord, endWord, temp);
        return re;
    }

    bool buildGraph(string &beginWord, string &endWord, vector<string> &wordList)
    {
        unordered_set<string> remain(wordList.begin(), wordList.end());
        if (remain.find(endWord) == remain.end())
        {
            return false;
        }
        unordered_set<string> curLay, nextLay;
        curLay.insert(beginWord);
        remain.erase(beginWord);
        while (!curLay.empty())
        {
            for (string curWord : curLay)
            {
                string nextword(curWord);
                for (int i = 0; i < nextword.length(); i++)
                {
                    char origin = nextword[i];
                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        if (j == origin)
                        {
                            continue;
                        }
                        nextword[i] = j;
                        if (remain.find(nextword) != remain.end())
                        {
                            nextLay.insert(nextword);
                            map[nextword].emplace_back(curWord);
                        }
                    }
                    nextword[i] = origin;
                }
            }
            for (auto &word : nextLay)
            {
                remain.erase(word);
            }
            if (nextLay.find(endWord) != nextLay.end())
            {
                return true;
            }
            curLay.clear();
            swap(curLay, nextLay);
        }
        return false;
    }

    void dfsBuildList(string &beginWord, string &endWord, vector<string> curList)
    {
        if (beginWord == endWord)
        {
            re.emplace_back(vector<string>(curList.rbegin(), curList.rend()));
            return;
        }
        for (auto &lastWord : map[endWord])
        {
            curList.push_back(lastWord);
            dfsBuildList(beginWord, lastWord, curList);
            curList.pop_back();
        }
    }
};