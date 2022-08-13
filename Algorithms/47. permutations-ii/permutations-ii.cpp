/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * Method: Backtracking
 * Data Structure: Hash Table
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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

        // use hash table to skip duplicates
        unordered_set<int> s;

        // Recursion get permutation: O(n!)
        // T(1) = 1
        // T(n) = n * T(n-1)
        for (int i = pos; i < nums.size(); i++) {
            // if same number was swapped before, continue
            if (s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            // same as problem 46
            swap(nums[pos], nums[i]);
            getPermutations(ans, nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
    }
};
// @lc code=end
