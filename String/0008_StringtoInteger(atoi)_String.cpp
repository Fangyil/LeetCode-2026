//Runtime: 0ms, Beats: 100.00%
// ref. Pradhuman Gupta -- https://leetcode.com/problems/string-to-integer-atoi/solutions/6540523/beats-100-beginner-friendly-explanation-b8lfb/

#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i, sign, digit;
        long ans;  // Using long to handle overflow cases

        i = ans = 0;
        sign = 1;

        // Whitespace
        while (s[i] == ' ')
            i++;
        if (i == s.size())
            return 0;

        // Signedness
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+')
            i++;
        if (i == s.size())
            return 0;

        // Conversion
        while (s[i] == '0')
            i++;
        if (i == s.size())
            return 0;

        // start to numerical
        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // overflow or not
            if (sign * ans > INT_MAX)
                return INT_MAX;
            if (sign * ans < INT_MIN)
                return INT_MIN;

            i++;
        }
        return (int)sign * ans;
    }
};