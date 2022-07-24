/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * Methods: Backtracking
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0);  // O(n*n!)
        return ans;
    }

private:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int pos) {
        if (pos == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        // recursion: O(n*n!)
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            backtrack(ans, nums, pos + 1);  // O(n!)
            swap(nums[pos], nums[i]);
        }
    }
};
// @lc code=end
