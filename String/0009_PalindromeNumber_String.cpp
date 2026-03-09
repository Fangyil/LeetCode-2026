/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
// Runtime: 0 ms, Beats: 100 %

#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        string s = to_string(x);
        int length = s.length();

        for (int i = 0; i < length / 2; i++)
            if (s[i] != s[length - 1 - i])
            {
                // cout << "i:" << i << " " << s[i] << endl
                //      << "length-i: " << length - i << " " << s[length - i] << endl;
                return false;
            }

        return true;
    }
};
// @lc code=end
