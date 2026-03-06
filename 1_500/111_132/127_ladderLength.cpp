/* 127. 单词接龙
字典 wordList 中从单词 beginWord 到 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：

每一对相邻的单词只差一个字母。
 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
sk == endWord
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。 */
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int re = 1;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        {
            return 0;
        }
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> remains(wordList.begin(), wordList.end());
        while (!que.empty())
        {
            re++;
            int size = que.size();
            unordered_set<string> nextLay;
            for (int i = 0; i < size; i++)
            {
                string word = que.front();
                que.pop();
                for (int j = 0; j < word.size(); j++)
                {
                    char origin = word[j];
                    for (char k = 'a'; k <= 'z'; k++)
                    {
                        if (k == origin)
                        {
                            continue;
                        }
                        word[j] = k;
                        if (remains.find(word) != remains.end())
                        {
                            if (word == endWord)
                            {
                                return re;
                            }
                            nextLay.insert(word);
                            que.push(word);
                        }
                    }
                    word[j] = origin;
                }
            }
            for (auto &word : nextLay)
            {
                remains.erase(word);
            }
        }
        return 0;
    }
};