//Runtime: 0ms, Beats: 100.00%

class Solution {
  public:
    int divide(int dividend, int divisor) {
        long long ans = (long long)dividend / divisor;

        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;

        return (int)ans;
    }
};
