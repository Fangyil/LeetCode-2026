// Runtime: 0ms, Beats: 100.00%
#include <iostream>
using namespace std;

class Solution {
  public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        int count, i, j;

        count = i = j = 0;

        // sorting at first to speed up comparing
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};
