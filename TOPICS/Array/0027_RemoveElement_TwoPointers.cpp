// Runtime: 0ms, beats: 100%

#include <iostream>
using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {

        int j = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[j++] = nums[i];

        // // check situation
        // cout << "nums: ";
        // for (int i = 0; i < nums.size(); i++) {
        //     cout << nums[i] << " ";
        // }

        return j;
    }
};
