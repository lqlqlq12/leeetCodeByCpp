/* 68. 文本左右对
给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

注意:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
*/
#include <string>
#include <vector>
using namespace std;
// This4is4an
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int len = words.size(), currLen = words[0].size(), start = 0;
        vector<string> re;
        for (int i = 1; i < len; i++)
        {
            if (currLen + words[i].size() + 1 <= maxWidth)
            {
                currLen += (words[i].size() + 1);
                continue;
            }
            int remainEscape = maxWidth - currLen;
            int gapeCount = i - start - 1;
            int remain = gapeCount != 0 ? remainEscape % gapeCount : 0;
            string item = words[start];
            for (int j = start + 1; j < i; j++)
            {
                if (remain > 0)
                {
                    item += (string(remainEscape / gapeCount + 2, ' ') + words[j]);
                    remain--;
                }
                else
                {
                    item += (string(remainEscape / gapeCount + 1, ' ') + words[j]);
                }
            }
            item += string(maxWidth - item.size(), ' ');
            start = i;
            currLen = words[i].size();
            re.push_back(item);
        }
        string lastItem = words[start];
        for (int i = start + 1; i < len; i++)
        {
            lastItem += (' ' + words[i]);
        }
        lastItem += string(maxWidth - lastItem.size(), ' ');
        re.push_back(lastItem);
        return re;
    }
};