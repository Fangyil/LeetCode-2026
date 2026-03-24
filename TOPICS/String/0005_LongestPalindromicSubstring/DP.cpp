//Runtime: 314ms, Beats: 15.62%
//using dynamic programming, worse than v3 (但我還是不會dp QQ)
//ref. https://dev.to/shikky/solving-the-longest-palindromic-substring-on-leetcode-with-c-ga5

#include <iostream>
using namespace std;

class Solution {
private:
    // check  palindromic
    bool solve(vector<vector<bool>>& dp, string& s, int l, int r) {
        if (l == r)
            return dp[l][r] = true;
        if (r - l == 1 && s[l] == s[r])
            return dp[l][r] = true;
        if (s[l] == s[r] && dp[l + 1][r - 1])
            return dp[l][r] = true;
        return dp[l][r] = false;
    }

public:
    string longestPalindrome(string s) {
        int inputStringSize = s.size();
        int lOfMaxLength = 0, maxLength = 0;
        vector<vector<bool>> dp(inputStringSize,
                                vector<bool>(inputStringSize, false));
        for (int i = 0; i < inputStringSize; i++)
            for (int l = 0, r = i; r < inputStringSize; l++, r++) {
                solve(dp, s, l, r);
                if (dp[l][r] == true)
                    if (r - l + 1 > maxLength) {
                        lOfMaxLength = l;
                        maxLength = r - l + 1;
                    }
            }
        return s.substr(lOfMaxLength, maxLength);
    }
};
