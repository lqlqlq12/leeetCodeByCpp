/* 118. 杨辉三角
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> re(numRows);
        for (int i = 0; i < numRows; i++)
        {
            re[i].resize(i+1);
            re[i][0] = re[i][i] = 1;
            for (int index = 1; index < i; index++)
            {
                re[i][index] = re[i-1][index-1] + re[i-1][index];
            }
        }
        return re;
    }
};