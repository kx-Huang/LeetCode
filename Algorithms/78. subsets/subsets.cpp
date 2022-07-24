/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * Methods: Backtracking
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        backtrack(ans, subset, nums, 0);
        return ans;
    }

private:
    void backtrack(vector<vector<int>>& ans, vector<int>& subset,
                   vector<int>& nums, int pos) {
        // To leaf of binary tree, add subset to answer and return
        if (pos == nums.size()) {
            ans.push_back(subset);  // O(n) per recursion
            return;
        }
        // Recursion: O(2^n)
        // add left node: with nums[pos]
        subset.push_back(nums[pos]);
        backtrack(ans, subset, nums, pos + 1);
        // add right node: without nums[pos]
        subset.pop_back();
        backtrack(ans, subset, nums, pos + 1);
    }
};
// @lc code=end
