// Runtime: 3ms, beats: 27.34%

#include <iostream>
using namespace std;

class Solution {
  private:
    void dfs(vector<int> &used, vector<int> &path, vector<int> &nums, vector<vector<int>> &permutation) {

        if (path.size() == nums.size()) {
            permutation.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue; // 已用過

            // 選
            used[i] = true;
            path.push_back(nums[i]);

            // 遞迴
            dfs(used, path, nums, permutation);

            // 回溯
            path.pop_back();
            used[i] = false;
        }
    }

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> permutation;
        vector<int> path, used;

        used.resize(nums.size(), false);
        dfs(used, path, nums, permutation);

        return permutation;
    }
};
