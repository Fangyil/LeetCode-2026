//Runtime: 3ms, Beats: 19.50%
//brute force? only check four directions of "1" 

#include <iostream>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int i, j, k;
        int count = 0, flip;

        // cout << mat.size() << endl;
        for (i = 0; i < mat.size(); i++) {
            flip = 0;
            for (j = 0; j < mat[i].size(); j++) {
                // cout << mat[i][j];
                if (mat[i][j]) {

                    // 向上找
                    k = i - 1;
                    while (k > -1) {
                        if (mat[k][j]) {
                            flip = 1;
                            break;
                        }
                        k--;
                    }

                    // 向下找
                    k = i + 1;
                    while (k < mat.size()) {
                        if (mat[k][j]) {
                            flip = 1;
                            break;
                        }
                        k++;
                    }

                    // 向左找
                    k = j - 1;
                    while (k > -1) {
                        if (mat[i][k]) {
                            flip = 1;
                            break;
                        }
                        k--;
                    }

                    // 向右找
                    k = j + 1;
                    while (k < mat[i].size()) {
                        if (mat[i][k]) {
                            flip = 1;
                            break;
                        }
                        k++;
                    }
                    // cout << "i: " << i << ", j: " << j << endl;
                    if (!flip)
                        count++;
                }
            }
            // cout << endl;
        }
        return count;
    }
};