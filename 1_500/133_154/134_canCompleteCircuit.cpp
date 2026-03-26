/* 134. 加油站
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。 */
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = -1, n = gas.size();
        vector<int> newGas, newCost;
        newGas.insert(newGas.end(), gas.begin(), gas.end());
        newGas.insert(newGas.end(), gas.begin(), gas.end());
        newCost.insert(newCost.end(), cost.begin(), cost.end());
        newCost.insert(newCost.end(), cost.begin(), cost.end());

        while (start < n)
        {
            int curGas = 0, curCost = 0, newIndex = start;
            while (curGas >= curCost && newIndex < start + n)
            {
                newIndex++;
                curGas += newGas[newIndex];
                curCost += newCost[newIndex];
            }
            if (curGas >= curCost)
            {
                return start + 1;
            }
            start = newIndex;
        }
        return -1;
    }
};