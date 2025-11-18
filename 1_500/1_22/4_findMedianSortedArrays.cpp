#include <vector>
#include <iostream>
using namespace std;

class Solution {
   private:
    vector<int> nums1_;
    vector<int> nums2_;

   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1_ = nums1;
        nums2_ = nums2;
        int size = nums1.size() + nums2.size();
        if (size % 2 == 0) {
            return (findKthNumber(0, 0, size / 2) +
                    findKthNumber(0, 0, size / 2 + 1)) /
                   2.0;
        }
        return findKthNumber(0, 0, size / 2 + 1);
    }

    int findKthNumber(int start1, int start2, int targetK) {
        if (start1 == nums1_.size()) {
            return nums2_[start2 + targetK - 1];
        } else if (start2 == nums2_.size()) {
            return nums1_[start1 + targetK - 1];
        }
        if (targetK == 1) {
            return nums1_[start1] > nums2_[start2] ? nums2_[start2] : nums1_[start1];
        }
        int half = targetK / 2;
        int l1 = (half + start1) > nums1_.size() ? nums1_.size() : half + start1;
        int l2 = (half + start2) > nums2_.size() ? nums2_.size() : half + start2;
        if (nums1_[l1 - 1] > nums2_[l2 - 1]) {
            return findKthNumber(start1, l2, targetK - l2 + start2);
        } else {
            return findKthNumber(l1, start2, targetK - l1 + start1);
        }
    }
};

int main () {
    Solution s;
    vector<int> n1 = {1,2};
    vector<int> n2 = {3,4};
    cout << s.findMedianSortedArrays(n1,n2) << endl;
}