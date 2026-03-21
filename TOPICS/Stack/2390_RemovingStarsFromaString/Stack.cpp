//Runtime: 20ms, Beats: 47.92%
//s.erase(s.begin()); -> O(n²) ,lots of memory movement

#include<iostream>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string ans;

        for (char c : s) {
            if (c == '*')
                ans.pop_back();
            else
                ans.push_back(c);
        }

        return ans;
    }
};
