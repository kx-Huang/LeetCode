/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 *
 * Method: Backtracking, Depth First Search
 * Data Structure: Hash Table
 *
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;

    void dfs(vector<int> &seq, vector<int> &nums, int pos) {
        // push sequence to answer vector if length is larger than 2
        if (seq.size() >= 2) ans.push_back(seq);  // O(n)

        // use set to prevent recursions with same sequence
        unordered_set<int> s;

        // Recursion get subset: O(2^n)
        // T(1) = 2
        // T(n) = 2 * T(n-1) (upper bound)
        for (int i = pos; i < nums.size(); i++) {
            int num = nums[i];
            // if we have searched one number, don't do it again for same number
            if (s.find(num) != s.end()) continue;
            // find an equal or larger number (or sequence is empty)
            if (seq.empty() || num >= seq.back()) {
                seq.push_back(num);
                dfs(seq, nums, i + 1);
                s.insert(num);
                seq.pop_back();  // backtracking
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        vector<int> seq;
        dfs(seq, nums, 0);  // O(n*2^n)
        return ans;
    }
};
// @lc code=end
