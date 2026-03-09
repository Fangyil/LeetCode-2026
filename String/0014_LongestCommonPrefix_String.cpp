//Runtime: 0ms, Beats: 100.00%

#include<iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, j;
        string ans = strs[0];      //預設第一個str會是最長共同子序列

        for (i = 1; i < strs.size(); i++)
            for (j = 0; j < ans.length(); j++) {
                if (ans[j] != strs[i][j] || j > strs[i].length()) { //有不同或出現更小序列時，ans超過的都刪掉
                    ans.erase(ans.begin() + j, ans.end());
                    break;
                }
            }

        return ans;
    }
};