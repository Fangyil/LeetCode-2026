//Runtime: 0ms, Beats: 100.00%
//just using a funtion, learn something new

#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        for (int i = 0; i < k / 2; i++) {
            swap_ranges(grid[x + i].begin() + y, grid[x + i].begin() + y + k,
                        grid[x + k - 1 - i].begin() + y);
            // cout << x << " " << grid[x][y] << " " << x + k - 1 - i << " "
            //      << grid[x + k - 1 - i][y] << endl;
        }
        return grid;
    }
};
