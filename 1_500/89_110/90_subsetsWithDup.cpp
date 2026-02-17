/* 90. 子集 II
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> re;
        vector<int> t;
        re.emplace_back(t);
        t.emplace_back(nums[0]);
        re.emplace_back(t);
        int n = nums.size(),lastSize = 1;
        for (int i=1;i<n;i++){
            int start =0,size = re.size();
            if (nums[i]==nums[i-1]){
                start = lastSize;
            }
            lastSize = size;
            while (start<size)
            {
                vector<int> t = re[start++];
                t.push_back(nums[i]);
                re.push_back(t);
            }
        }
        return re;
    }
};