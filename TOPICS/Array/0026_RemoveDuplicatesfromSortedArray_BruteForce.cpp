//runtime beats 100 %

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        vector<int> ans;

        int j = 0;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            if (ans[j] != nums[i]) {
                ans.push_back(nums[i]);
                j++;
            }
        nums = ans;

        return ans.size();
    }
};
