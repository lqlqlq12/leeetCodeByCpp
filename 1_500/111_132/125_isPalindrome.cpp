/* 125. 验证回文串
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。 */
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int len = s.size(), left = 0, right = len - 1;
        while (left <= right)
        {
            char l = ' ', r = ' ';
            while (left <= right)
            {
                char t = s[left];
                if (isLetter(t))
                {
                    l = t;
                    break;
                }
                left++;
            }
            while (left <= right)
            {
                char t = s[right];
                if (isLetter(t))
                {
                    r = t;
                    break;
                }
                right--;
            }
            l |= 0x20;
            r |= 0x20;
            if (l != r)
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool isLetter(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
};

int main()
{
    Solution sol;
    sol.isPalindrome("A man, a plan, a canal: Panama");
}