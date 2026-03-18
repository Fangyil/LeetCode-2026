//Runtime: 91ms, Beats: 7.64%

#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size())                                //空字串不用比
            return 0;

        int i, j, maxAns;
        string ans[s.size()];

        j = maxAns = 0;
        for (i = 0; i < s.length(); i++) {
            // cout << j << endl;
            // cout << ans[j] << " " << s[i] << endl;
            // cout << ans[j].find(s[i]) << endl;
            if (ans[j].find(s[i]) < ans[j].size()) {  //相異字串遇見同字，從一開始遇見的同字後一位開始重新比
                j++;
                i = j;                                //程式慢的關鍵點
            }
            ans[j] += s[i];
            if (maxAns < ans[j].size())               //出現更長相異字串才更新
                maxAns = ans[j].size();
            // cout << endl;
        }

        return maxAns;
    }
};
