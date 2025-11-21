/* 28. 找出字符串中第一个匹配项的下标

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。 */

// KMP 构建next数组

#include <string>
using namespace std;
#include <vector>

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size(), index = 0;
        vector<int> next(n);
        int t = next[0];
        for (int i = 1; i < n; i++)
        {
            while (t > 0 && needle[t] != needle[i])
            {
                t = next[t - 1];
            }
            if (needle[t] == needle[i])
            {
                t++;
            }
            next[i] = t;
        }
        for (int j = 0; j < m; j++)
        {
            while (index > 0 && needle[index] != haystack[j])
            {
                index = next[index - 1];
            }
            if (needle[index] == haystack[j])
            {
                index++;
                if (index == n)
                {
                    return j - n + 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    sol.strStr("mississippi", "issip");
    return 0;
}
