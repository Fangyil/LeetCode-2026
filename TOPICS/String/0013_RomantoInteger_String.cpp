#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int i, ans;
        char buffer;

        ans = 0;
        for (i = s.length() - 1; i > -1; i--) {
            if (i < s.length())          //紀錄上一個符號
                    buffer = s[i + 1];
            switch (s[i]) {
            case 'I':
                if (buffer == 'V' || buffer == 'X')
                    ans -= 1;
                else
                    ans += 1;
                break;
            case 'V':
                ans += 5;
                break;
            case 'X':
                if (buffer == 'L' || buffer == 'C')
                    ans -= 10;
                else
                    ans += 10;
                break;
            case 'L':
                ans += 50;
                break;
            case 'C':
                if (buffer == 'D' || buffer == 'M')
                    ans -= 100;
                else
                    ans += 100;
                break;
            case 'D':
                ans += 500;
                break;
            case 'M':
                ans += 1000;
                break;
            }
            // cout << "buffer: " << buffer << " " << ans << endl;
        }

        return ans;
    }
};
