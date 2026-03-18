#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int i, j, d, offset;
        string ans;

        d = (numRows - 1) * 2; // 類公差
        if (!d)
            return s;
        for (i = 0; i < numRows; i++) {
            offset = i; // 偏移量
            j = 0;
            if (i != 0 && i != numRows - 1)
                j = i;
            while (offset < s.length()) {
                // cout << s[offset] << " " << offset << endl;

                ans += s[offset];
                offset += d - 2 * j;

                // cout << "d: " << d << " ";
                // cout << "j: " << j << " " << d - 2 * j << endl;

                if (i != 0 && i != numRows - 1) { //計算間隔偏差(?,2)
                    if (j == i)
                        j = numRows - 1 - i;
                    else
                        j = i;
                }
            }
        }
        return ans;
    }
};
