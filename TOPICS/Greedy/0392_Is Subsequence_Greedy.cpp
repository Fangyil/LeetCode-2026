// Runtime: 0ms, beats: 100.00%

#include <iostream>
using namespace std;

class Solution {
  public:
    bool isSubsequence(string s, string t) {
        int i, j, count;

        i = j = count = 0;
        while (i <= j && i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                count++;
            }
            j++;
        }

        if (count == s.size())
            return true;
        return false;
    }
};
