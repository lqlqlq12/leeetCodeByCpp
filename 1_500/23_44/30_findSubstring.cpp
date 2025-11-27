/* 30. 串联所有单词的子串
给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，
因为他不是任何 words 排列的连接。
返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。 abcdefaaa */
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring_1(string s, vector<string> &words)
    {
        vector<int> ans;
        unordered_map<string, int> origin_map;
        int len = words[0].size(), n = words.size();
        for (size_t i = 0; i < words.size(); i++)
        {
            if (origin_map.find(words[i]) == origin_map.end())
            {
                origin_map[words[i]] = 1;
            }
            else
            {
                origin_map[words[i]] = origin_map[words[i]] + 1;
            }
        }
        for (int i = 0; i < len && i + n * len <= s.size(); i++)
        {
            int left = i, right = left + n * len, remains = origin_map.size();
            unordered_map<string, int> map = origin_map;
            for (int j = left; j < right; j += len)
            {
                string word = s.substr(j, len);
                if (map.find(word) != map.end())
                {
                    map[word] = map[word] - 1;
                    if (map[word] == 0)
                    {
                        remains--;
                    }
                    else if (map[word] == -1)
                    {
                        remains++;
                    }
                }
            }
            if (remains == 0)
            {
                ans.push_back(left);
            }

            for (; right <= s.size() - len; right += len, left += len)
            {
                string pop = s.substr(left, len);
                string push = s.substr(right, len);
                if (map.find(pop) != map.end())
                {
                    map[pop] = map[pop] + 1;
                    if (map[pop] == 0)
                    {
                        remains--;
                    }
                    else if (map[pop] == 1)
                    {
                        remains++;
                    }
                }
                if (map.find(push) != map.end())
                {
                    map[push] = map[push] - 1;
                    if (map[push] == 0)
                    {
                        remains--;
                    }
                    else if (map[push] == -1)
                    {
                        remains++;
                    }
                }
                if (remains == 0)
                {
                    ans.push_back(left + len);
                }
            }
        }
        return ans;
    }

    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> re;
        unordered_map<string, int> origin_map;
        for (string &str : words)
        {
            origin_map[str]++;
        }
        int len = words[0].size(), n = words.size();
        for (int i = 0; i < len && i + n * len <= s.size(); i++)
        {
            unordered_map map = origin_map;
            for (int j = 0; j < n; j++)
            {
                string word = s.substr(i + j * len, len);
                if (--map[word] == 0)
                {
                    map.erase(word);
                }
            }
            if (map.empty())
            {
                re.push_back(i);
            }
            for (int j = i; j + n * len + len <= s.size(); j += len)
            {
                string word = s.substr(j, len);
                if (++map[word] == 0)
                {
                    map.erase(word);
                }
                word = s.substr(j + n * len, len);
                if (--map[word] == 0)
                {
                    map.erase(word);
                }
                if (map.empty())
                {
                    re.push_back(j + len);
                }
            }
        }
        return re;
    }
};

int main()
{
    Solution sol;
    vector<string> ve{"bar","foo","the"};
    sol.findSubstring("barfoofoobarthefoobarman", ve);
    return 0;
}