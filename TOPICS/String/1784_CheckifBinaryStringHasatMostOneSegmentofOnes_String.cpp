//Runtime: 0ms, Beats; 100.00%

#include<iostream>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int i;

        for (i = 0; i < s.length() - 1; i++)
            if (s[i] == '0' && s[i + 1] == '1')   //因為開頭必1，所以若後續有01發生即超過1個segment
                return false;
        return true;
    }
};
