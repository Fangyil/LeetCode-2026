//Runtime: 861ms, Beats: 8.04%
//using Brute-Force
//ref. 1 - https://medium.com/@flyotlin/leetcode-5-longest-palindromic-substring-63aa3b4943e3
//     2 - https://github.com/flyotlin/leetcode/blob/main/5-longest-palindromic-substring/3.cpp?source=post_page-----63aa3b4943e3---------------------------------------

#include <iostream>
using namespace std;

class Solution {
private:
    string s;
    bool isPalindrome(int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }

public:
    string longestPalindrome(string ss) {
        s = ss;
        if (s.size() == 1) {
            return s;
        }

        int maxLen = 0;
        int start = 0;
        for (int k = 0; k < s.size(); k++) {
            for (int i = 0, j = k; j < s.size(); i++, j++) {
                if (isPalindrome(i, j)) {
                    if (j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
