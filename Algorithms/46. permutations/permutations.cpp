/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0);
        return ans;
    }

private:
    // Backtracking
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int pos) {
        if (pos == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            backtrack(ans, nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
    }
};
// @lc code=end
