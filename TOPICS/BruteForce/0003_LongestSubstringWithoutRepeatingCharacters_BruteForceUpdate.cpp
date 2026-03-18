//Runtime: 19ms, Beats: 27.83%

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
            if (ans[j].find(s[i]) < ans[j].size()) {
                ans[j + 1] = ans[j].substr(ans[j].find(s[i]) + 1); //修改處，直接搬重複處後一位的字串到另一組內
                j++;
            }
            ans[j] += s[i];
            if (maxAns < ans[j].size())               //出現更長相異字串才更新
                maxAns = ans[j].size();
            // cout << endl;
        }

        return maxAns;
    }
};
