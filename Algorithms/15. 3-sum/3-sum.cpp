/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * Methods: Two Pointers
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

        // for each number < 0, search for its complementary pairs
        for (int i = 0; i < nums.size() - 1; i++) {
            // prevent first number duplicate
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            // prevent duplicates: only search with non-positive first number
            if (target < 0) break;

            // two pointers
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    // found one triplet
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    ans.push_back(triplet);
                    // prevent second number duplicate
                    while (left < right && nums[left] == triplet[1]) left++;
                    // prevent third number duplicate
                    while (left < right && nums[left] == triplet[2]) right--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
