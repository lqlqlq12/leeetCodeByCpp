/* 71. 简化路径
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为 更加简洁的规范路径。

在 Unix 风格的文件系统中规则如下：

一个点 '.' 表示当前目录本身。
此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
任意多个连续的斜杠（即，'//' 或 '///'）都被视为单个斜杠 '/'。
任何其他格式的点（例如，'...' 或 '....'）均被视为有效的文件/目录名称。
返回的 简化路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        int len = path.size(), index = 0, j;
        vector<string> stack;
        for (; index < len;)
        {
            char c = path[index];
            switch (c)
            {
            case '/':
                j = index;
                while (j < len && path[j] == '/')
                {
                    j++;
                }
                index = j;
                break;
            case '.':
            {
                int count = 1;
                j = index + 1;
                while (j < len && path[j] != '/')
                {
                    if (path[j] == '.')
                    {
                        count++;
                    }
                    j++;
                }
                if (j - index == count)
                {
                    if (count == 2)
                    {
                        if (stack.size() != 0)
                        {
                            stack.pop_back();
                        }
                    }
                    else if (count >= 3)
                    {
                        stack.push_back(path.substr(index, count));
                    }
                }
                else
                {
                    stack.push_back(path.substr(index, j - index));
                }
                index = j + 1;
                break;
            }
            default:
                j = index;
                while (j < len && path[j] != '/')
                {
                    j++;
                }
                stack.push_back(path.substr(index, j - index));
                index = j + 1;
            }
        }
        string re;
        while (stack.size() != 0)
        {
            re = ("/" + stack.back()) + re;
            stack.pop_back();
        }
        return re.size() != 0 ? re : "/";
    }
};

int main()
{
    Solution sol;
    string path = "/home/user/Documents/../Pictures";
    sol.simplifyPath(path);
}