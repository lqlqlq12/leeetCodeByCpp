/* 45. 跳跃游戏 II
给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。

每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意 (i + j) 处：

0 <= j <= nums[i] 且
i + j < n
返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。 */

#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int len = nums.size(), k = 1, cur = nums[0], last = 0;
        if (len == 1)
        {
            return 0;
        }
        while (cur < len - 1)
        {
            int max = 0;
            for (int i = last + 1; i <= cur; i++)
            {
                if (i + nums[i] > max)
                {
                    max = i + nums[i];
                }
            }
            last = cur;
            cur = max;
            k++;
        }
        return k;
    }
};