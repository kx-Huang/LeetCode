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
        getSubsets(ans, subset, nums, 0);  // O(n*2!)
        return ans;
    }

private:
    void getSubsets(vector<vector<int>>& ans, vector<int>& subset,
                    vector<int>& nums, int pos) {
        ans.push_back(subset);  // O(n)
        if (pos == nums.size()) return;

        // Recursion get subset: O(2^n)
        // T(1) = 2
        // T(n) = 2T(n-1)
        for (int i = pos; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            getSubsets(ans, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};
// @lc code=end
