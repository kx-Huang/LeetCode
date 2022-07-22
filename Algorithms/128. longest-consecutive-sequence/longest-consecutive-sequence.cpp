/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // construct set with iterator of vector
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLength = 0;
        int currentCount = 1;

        // count consecutives only if a number is the start of a sequence
        for (int i = 0; i < nums.size(); i++) {
            int currentNum = nums[i];
            if (s.find(currentNum - 1) != s.end()) continue;
            while (s.find(++currentNum) != s.end()) currentCount++;
            maxLength = max(currentCount, maxLength);
            currentCount = 1;
        }
        return maxLength;
    }
};
// @lc code=end
