//Runtime: 0ms, Beats: 100.00%
//feel like I don't even have to use "stack"

#include<iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        int i;
        char t;

        if (s.length() % 2)
            return false;

        for (i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                mystack.push(s[i]);
            else if (!mystack.empty()) {
                t = mystack.top();
                if (t == '{' && s[i] != '}')
                    return false;
                if (t == '(' && s[i] != ')')
                    return false;
                if (t == '[' && s[i] != ']')
                    return false;
                mystack.pop();
            } else
                return false;
        }
        
        if (mystack.empty())
            return true;
        return false;
    }
};
