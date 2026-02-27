/* 87. 扰乱字符串
使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
如果字符串的长度为 1 ，算法停止
如果字符串的长度 > 1 ，执行下述步骤：
在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。 */
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string s1, s2;
    vector<int> dp;
    int len;

    int &at(int i, int j, int k)
    {
        return dp[i * len * (len + 1) + j * (len + 1) + k];
    }

    bool isScramble(string s1, string s2)
    {
        this->len = s1.size();
        this->s1 = s1;
        this->s2 = s2;
        dp = vector<int>(len * len * (len + 1));
        return dfs(0, 0, len);
    }

    bool dfs(int index1, int index2, int length)
    {
        if (at(index1, index2, length) != 0)
        {
            return at(index1, index2, length) == 1;
        }
        if (s1.substr(index1, length) == s2.substr(index2, length))
        {
            at(index1, index2, length) = 1;
            return true;
        }
        vector<int> arr1(26), arr2(26);
        for (int i = 0; i < length; i++)
        {
            arr1[s1[index1 + i] - 'a']++;
            arr2[s2[index2 + i] - 'a']++;
        }
        if (arr1 != arr2)
        {
            at(index1, index2, length) = -1;
            return false;
        }
        for (int i = 1; i < length; i++)
        {
            if ((dfs(index1, index2, i) && dfs(index1 + i, index2 + i, length - i)) || (dfs(index1, index2 + length - i, i) && dfs(index1 + i, index2, length - i)))
            {
                at(index1, index2, length) = 1;
                return true;
            }
        }
        at(index1, index2, length) = -1;
        return false;
    }
};