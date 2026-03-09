//Runtime: 0ms, Beats: 100.00%
//using two pointers and store addr
//ref: https://yuihuang.com/lc-3/

#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size()) // 空字串不用比
            return 0;

        int i, l, r, maxAns, ans[128] = {0};

        maxAns = 0;
        for (l = 0, r = 0; r < s.length(); r++) {
            l = max(ans[s[r]], l);
            maxAns = max(maxAns, r - l + 1);
            ans[s[r]] = r + 1;
        }

        return maxAns;
    }
};