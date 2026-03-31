// Runtime: 0ms, beats: 100%

#include <iostream>
using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m, n;
        int up, down, left, right, column, row;
        bool find = false, keep = false;

        m = matrix.size();
        n = matrix[0].size();

        up = 0;
        down = m - 1;
        left = 0;
        right = n - 1;

        while (up <= down && up < m && down > -1) {
            row = (up + down) / 2;
            if (matrix[row][right] == target)
                return true;
            if (matrix[row][right] > target && matrix[row][left] <= target) {
                keep = true;
                break;
            }
            if (matrix[row][right] < target)
                up = row + 1;
            else if (matrix[row][right] > target)
                down = row - 1;
        }

        while (keep & left <= right && left < n && right > -1) {
            column = (left + right) / 2;
            if (matrix[row][column] == target)
                return true;
            if (matrix[row][column] > target && matrix[row][column - 1] < target)
                break;
            if (matrix[row][column] < target)
                left = column + 1;
            else if (matrix[row][column] > target)
                right = column - 1;
        }

        return find;
    }
};
