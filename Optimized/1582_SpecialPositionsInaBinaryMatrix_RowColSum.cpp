//Runtime: 0ms, Beats: 100.00%
//ridiculous, 只是把1整理一下

#include <iostream>
using namespace std;

class Solution {
private:
    int checkRow(vector<vector<int>>& mat, int i, int j) {
        int flip = 0;
        int temp = j;

        while (temp < mat[i].size()) {
            if (flip && mat[i][temp])
                return 1;
            else if (mat[i][temp])
                flip = 1;
            temp++;
        }

        flip = 0;
        while (j > -1) {
            if (flip && mat[i][j])
                return 1;
            else if (mat[i][j])
                flip = 1;
            j--;
        }
        return 0;
    }

    int checkColumn(vector<vector<int>>& mat, int i, int j) {
        int flip = 0;
        int temp = i;

        while (temp < mat.size()) {
            if (flip && mat[temp][j])
                return 1;
            else if (mat[temp][j])
                flip = 1;
            temp++;
        }

        flip = 0;
        while (i > -1) {
            if (flip && mat[i][j])
                return 1;
            else if (mat[i][j])
                flip = 1;
            i--;
        }
        return 0;
    }

public:
    int numSpecial(vector<vector<int>>& mat) {
        int i, j, k;
        int count = 0, flipR, flipC;

        for (i = 0; i < mat.size(); i++)
            for (j = 0; j < mat[i].size(); j++)
                if (mat[i][j]) {
                    // cout << "i: " << i << ", j: " << j << endl;
                    flipR = checkRow(mat, i, j);
                    // cout << "Row: " << flipR << endl;
                    flipC = checkColumn(mat, i, j);
                    // cout << "Column: " << flipC << endl;
                    if (!flipR && !flipC)
                        count++;
                }
        return count;
    }
};