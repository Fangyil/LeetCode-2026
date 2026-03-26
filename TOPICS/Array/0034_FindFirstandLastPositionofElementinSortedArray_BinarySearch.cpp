//Runtime: 0ms, beats: 100%

#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int left, right;
        int l, r, m, tmp;

        left = right = -1;
        l = m = 0;
        r = nums.size() - 1;
        while (l <= r) {
            if (target == nums[m]) {
                tmp = m;
                while (m > -1 && target == nums[m])
                    left = m--;
                m = tmp;
                while (m < nums.size() && target == nums[m])
                    right = m++;
                break;
            }
            if (target < nums[m])
                r = m - 1;
            else if (target > nums[m])
                l = m + 1;
            m = (l + r) / 2;
        }
        return {left, right};
    }
};
