/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * Method: Backtracking, Depth First Search
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutations(ans, nums, 0);  // O(n*n!)
        return ans;
    }

private:
    void getPermutations(vector<vector<int>>& ans, vector<int>& nums, int pos) {
        if (pos == nums.size() - 1) {
            ans.push_back(nums);  // O(n)
            return;
        }
        // Recursion get permutation: O(n!)
        // T(1) = 1
        // T(n) = n * T(n-1)
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            getPermutations(ans, nums, pos + 1);
            swap(nums[pos], nums[i]);  // backtracking
        }
    }
};
// @lc code=end
