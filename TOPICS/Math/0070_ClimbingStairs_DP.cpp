//Runtime: 0ms, Beats: 100.00%

#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
            
        vector<int> dp;

        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(2);
        for (int i = 3; i < n + 1; i++) {
            dp.push_back(dp[i - 1] + dp[i - 2]);
            // cout << dp[i - 1] << " " << dp[i - 2] << endl;
        }

        return dp.back();
    }
};
