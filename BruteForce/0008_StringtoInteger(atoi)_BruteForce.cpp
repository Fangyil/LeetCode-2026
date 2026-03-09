//Runtime: 3ms, Beats: 14.42%
//browse each char

#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i, ans, sign, digit;

        i = ans = sign = 0;

        while (s[i] == ' ')             // Whitespace
            i++;

        if (s[i] == '-') {              // Signedness
            sign = 1;
            i++;
        } else if (s[i] == '+')
            i++;
            
        while (s[i] == '0')             // Conversion
            i++;

        if (isdigit(s[i])) {             // change the sign
            digit = s[i] - '0';
            if (sign)
                ans = ans * -1;
            ans = ans * 10 + (!sign ? digit : -digit);
            i++;
        } else {
            return ans;
        }

        for (i; i < s.size(); i++) {
            if (isdigit(s[i])) {
                digit = s[i] - '0';

                if (ans > (INT_MAX - digit) / 10)       //overflow or not
                    return INT_MAX;
                if (ans < (INT_MIN + digit) / 10)
                    return INT_MIN;

                ans = ans * 10 + (!sign ? digit : -digit);
            } else {
                return ans;
            }
        }

        return ans;
    }
};