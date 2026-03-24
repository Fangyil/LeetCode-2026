//runtime beats 29.9 %

#include <iostream>
using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int i, j, m;
        vector<int> nums;

        i = j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                nums.push_back(nums1[i++]);
            else
                nums.push_back(nums2[j++]);
        }
        if (i == nums1.size())
            nums.insert(nums.end(), nums2.begin() + j, nums2.end());
        else if (j == nums2.size())
            nums.insert(nums.end(), nums1.begin() + i, nums1.end());

        m = nums.size() / 2;
        if (nums.size() % 2)
            return nums[m];
        return (nums[m - 1] + nums[m]) / 2.0;
    }
};
