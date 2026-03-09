//Runtime: 0ms, Beats: 100.00%
//ref. ChatGPT

#include<iostream>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int i;
        string ans;

        for (i = 0; i < nums.size(); i++)
            ans += (nums[i][i] == '0') ? '1' : '0';

        return ans;
    }
};