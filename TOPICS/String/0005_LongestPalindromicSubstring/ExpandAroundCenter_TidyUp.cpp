// Runtime: 2291ms, Beats: 5.01%
//just v1 tidy up, as bad as v1 (ref. https://vocus.cc/article/672addd2fd89780001160aae)

#include<iostream>
using namespace std;

class Solution {
public:
    // find longest palindromic
    string expandAroundCenter(string s, int l, int r, int initial) {
        string temp;
        if (initial > -1)
            temp = s[initial];
        while (l > -1 && r < s.length()) {
            if (s[l] != s[r])
                break;
            temp = s[l] + temp + s[r];
            l--;
            r++;
        }
        return temp;
    }

    string longestPalindrome(string s) {

        int i, ansLen;
        string ans, odd_palindromic, even_palindromic;

        ans.clear();
        for (i = 0; i < s.length(); i++) {
            odd_palindromic = expandAroundCenter(s, i - 1, i + 1, i);
            even_palindromic = expandAroundCenter(s, i, i + 1, -1);

            // cout << i << endl;
            // cout << "ans: " << ans << endl;
            // cout << "odd_palindromic: " << odd_palindromic << endl;
            // cout << "even_palindromic: " << even_palindromic << endl;

            ansLen = max(
                {ans.size(), odd_palindromic.size(), even_palindromic.size()});
            if (ansLen == odd_palindromic.size())
                ans = odd_palindromic;
            else if (ansLen == even_palindromic.size())
                ans = even_palindromic;
                
            // cout << "ans: " << ans << endl << endl;
        }
        return ans;
    }
};
