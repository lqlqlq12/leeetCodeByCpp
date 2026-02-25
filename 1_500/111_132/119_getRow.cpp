/* 119. 杨辉三角 II
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> re(rowIndex + 1);
        re[0] = 1;
        for (int i = 1; i <= rowIndex; i++)
        {
            re[i] = 1LL * re[i - 1] * (rowIndex - i + 1) / i;
        }
        return re;
    }
};