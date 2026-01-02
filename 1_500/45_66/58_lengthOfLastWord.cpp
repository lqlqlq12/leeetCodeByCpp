/* 58. 最后一个单词的长度
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。 */
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int index = s.size() - 1, length = 0;
        while (s[index] == ' ')
        {
            index--;
        }
        while (index >= 0 && s[index] != ' ')
        {
            index--;
            length++;
        }
        return length;
    }
};