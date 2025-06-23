#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// option shift F :格式化文档
// commandK commandF :格式化选中
// option shift A :块注释
// command / 逐个单行注释
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return {i, it->second};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    cout << "下标为: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}