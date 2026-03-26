//Runtime: 175 ms, beats: 1.78%

#include <iostream>
using namespace std;

class Solution {
  public:
    double myPow(double x, int n) {
        //deal with exceptional cases
        if (n == 0)
            return 1;
        if (x == 1)
            return 1;
        if (x == -1) {
            if (n % 2)
                return -1;
            return 1;
        }
        if (n > INT_MAX - 1)
            return 0;
        if (n < INT_MIN + 1)
            return 0;

        int sign = (n < 0) ? 1 : 0;
        int i = abs(n);
        double ans = x;

        for (i; i > 1; i--) {
            ans *= x;
            // cout << ans << endl;
        }
        if (sign)
            return 1 / ans;
        return ans;
    }
};
