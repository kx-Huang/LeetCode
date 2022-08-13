/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * Method: Boyer–Moore Majority Vote Algorithm
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return nums;

        int candidateA = INT_MAX;
        int candidateB = INT_MAX;
        int countA = 0;
        int countB = 0;

        // Boyer–Moore majority vote algorithm: O(n)
        for (int c : nums) {
            if (c == candidateA) {
                countA++;
            } else if (c == candidateB) {
                countB++;
            } else if (countA == 0) {
                candidateA = c;
                countA = 1;
            } else if (countB == 0) {
                candidateB = c;
                countB = 1;
            } else {
                countA--;
                countB--;
            }
        }

        // count vote for candidate A and B again to determine results: O(n)
        vector<int> ans;
        if (count(nums.begin(), nums.end(), candidateA) > len / 3)
            ans.push_back(candidateA);
        if (count(nums.begin(), nums.end(), candidateB) > len / 3)
            ans.push_back(candidateB);
        return ans;
    }
};
// @lc code=end
