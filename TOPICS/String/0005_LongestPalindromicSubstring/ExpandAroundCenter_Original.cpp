// Runtime: 2290ms, Beats: 5.01%
//  using "Expand Around Center", bad

#include<iostream>
using namespace std;

class Solution {                        
public:
    string longestPalindrome(string s) {
        int i, l, r;
        string ans, ansSet[s.length()], temp1[s.length()], temp2[s.length()];

        for (i = 0; i < s.length(); i++) {
            temp1[i] = s[i];
            temp2[i].clear();
            l = i - 1;
            r = i + 1;
            while (l > -1 && r < s.length()) { // odd palindromic substring
                if (s[l] != s[r])
                    break;
                temp1[i] = s[l] + temp1[i];
                temp1[i] += s[r];
                l--;
                r++;
            }
            r = i + 1;
            l = i;
            while (l > -1 && r < s.length()) { // even palindromic substring
                if (s[l] != s[r])
                    break;
                temp2[i] = s[l] + temp2[i] + s[r];
                r++;
                l--;
            }

            ansSet[i] = temp2[i];
            if (temp1[i].size() > temp2[i].size())
                ansSet[i] = temp1[i];
        }

        for (i = 0; i < s.length(); i++)
            if (ansSet[i].size() > ans.size())
                ans = ansSet[i];

        return ans;
    }
};
