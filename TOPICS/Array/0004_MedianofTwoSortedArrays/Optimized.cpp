//Runtime: 0ms, Beats: 100.00%

#include <iostream>
using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int i, j, k, m;
        vector<int> nums;

        i = j = k = 0;
        m = (nums1.size() + nums2.size()) / 2;
        while ((i < nums1.size() || j < nums2.size()) && m >= k) {
            if (i == nums1.size())
                nums.push_back(nums2[j++]);
            else if (j == nums2.size())
                nums.push_back(nums1[i++]);
            else if (nums1[i] < nums2[j])
                nums.push_back(nums1[i++]);
            else
                nums.push_back(nums2[j++]);
            k++;
        }

        if ((nums1.size() + nums2.size()) % 2)
            return nums[m];
        return (nums[m - 1] + nums[m]) / 2.0;
    }
};
