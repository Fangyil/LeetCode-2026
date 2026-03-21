//Runtime: 55ms, Beats: 24.87%
//using dp to speed up

#include <iostream>
using namespace std;

class Solution {
private:
    string form(string s[], int n) {
        if (!s[n].empty())
            return s[n];
        if (n == 1)
            return s[1] = "0";

        s[n] = form(s, n - 1) + '1' + reverse(invert(form(s, n - 1)));

        // cout << "n: " << n << " " << s << endl;
        return s[n];
    }
    string invert(string s) {
        // cout << "invert_before: " << s << endl;
        for (int i = 0; i < s.length(); i++) {
            s[i] = (s[i] - '0') ? '0' : '1';
            // cout << s[i];
        }
        // cout << "invert: " << s << endl;
        return s;
    }
    string reverse(string s) {
        int i, length;
        length = s.length();
        // cout << "reverse_before: " << s << endl;
        for (i = 0; i < length / 2; i++)
            swap(s[i], s[length - i - 1]);
        // cout << "reverse: " << s << endl;
        return s;
    }

public:
    char findKthBit(int n, int k) {
        string s[n + 1];
        s[n] = form(s, n);
        // cout << "n: " << n << " " << s << endl;
        return s[n][k - 1];
    }
};
