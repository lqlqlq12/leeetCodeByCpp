/* 76. 最小覆盖子串
给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，使得该子串包含 t 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。

测试用例保证答案唯一。 */
#include <string>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> map;
        for (int i = 0; i < t.size(); i++)
        {
            map[t[i]] += 1;
        }
        int remain = map.size(), left = 0, right = 0;
        for (; right < s.size(); right++)
        {
            char c = s[right];
            if (map.find(c) == map.end())
            {
                continue;
            }
            map[c]--;
            if (map[c] == 0)
            {
                remain--;
            }
            if (remain == 0)
            {
                break;
            }
        }
        if (right == s.size())
        {
            return "";
        }
        int minLen = right + 1;
        string re = s.substr(left, minLen);
        while (left < right && right < s.size())
        {
            char c = s[left];
            if (map.find(c) == map.end())
            {
                left++;
                continue;
            }
            if (map[c] < 0)
            {
                map[c] += 1;
                left++;
                continue;
            }
            while (right < s.size() && s[right] != s[left])
            {
                if (map.find(s[right]) != map.end())
                {
                    map[s[right]]--;
                }
                right++;
            }
            if (right == s.size())
            {
                return re;
            }
            while (left < right)
            {
                char cl = s[left];
                if (map.find(cl) == map.end())
                {
                    left++;
                    continue;
                }
                if (map[cl] < 0)
                {
                    map[cl]++;
                    left++;
                    continue;
                }
                break;
            }
            if (minLen > (right - left))
            {
                minLen = right - left;
                re = s.substr(left, minLen);
            }
            left++;
        }
        return re;
    }
};

int main()
{
    Solution sol;
    sol.minWindow("ADOBECODEBANC", "ABC");
}