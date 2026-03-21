//Runtime: 0ms, Beats: 100.00%
//only calculate 0101... or 1010...

#include<iostream>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int time1 = 0, time2 = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != (i % 2 ? '1' : '0'))
                time1++;

            if (s[i] != (i % 2 ? '0' : '1'))
                time2++;
        }

        return min(time1, time2);
    }
};
