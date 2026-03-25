//Runtime: 0ms, Beats: 100% 

#include <iostream>
using namespace std;

class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        int l, r, m;

        l = m = 0;
        r = nums.size() - 1;
        while (l <= r) {
            if (target == nums[m])
                break;
            if (target > nums[m])
                l = m + 1;
            if (target < nums[m])
                r = m - 1;
            m = (l + r) / 2;
        }
        if (target > nums[m])
            m++;

        return m;
    }
};
