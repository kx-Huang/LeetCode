/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * Method: Two Pointers
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // sort: O(nlogn)
        sort(nums.begin(), nums.end());

        // for each number < 0, search for its complementary pairs: O(n^2)
        for (int i = 0; i < nums.size() - 1; i++) {
            int first = nums[i];
            // skip same first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -first;
            int left = i + 1;
            int right = nums.size() - 1;

            // prevent duplicates: only search with non-positive first number
            if (target < 0) break;

            // two pointers: O(n)
            while (left < right) {
                int second = nums[left];
                int third = nums[right];
                int sum = second + third;
                if (sum == target) {
                    // found one triplet
                    ans.push_back({first, second, third});
                    // move to next slot
                    left++;
                    right--;
                    // skip same second number
                    while (left < right && nums[left] == second) left++;
                    // skip same third number
                    while (left < right && nums[left] == third) right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
