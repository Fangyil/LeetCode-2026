// Runtime: 0ms, beats: 100%

#include <iostream>
using namespace std;

class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {

            // If we can't even reach i, game over.
            if (i > farthest)
                return false;

            // Update the farthest position we can reach.
            farthest = max(farthest, i + nums[i]);

            // Already can reach the end.
            if (farthest >= nums.size() - 1)
                return true;
        }

        return true;
    }
};

// Wrong code
// U don't really need to jump and this concept is strange

// int NowSpace, NextSpace, bestStep, bestReach;
// if (nums.size() == 1)
//     return true;

// NowSpace = 0;
// NextSpace = nums[0];

// while (NowSpace < nums.size() - 1) {
//     step = 0;
//     NextSpace = nums[NowSpace];
//     if (!nums[NowSpace])
//         return false;
//     for (; NextSpace > 0; NextSpace--) {
//         cout << NowSpace << " " << NextSpace << " " << step << endl;
//         if (NowSpace == NowSpace + NextSpace)
//             return false;
//         if (step < NextSpace)
//             step = NextSpace;
//     }

//     NowSpace += step;
// }
