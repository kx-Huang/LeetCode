/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * Method: Two Pointers
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // if less or equal than 3 elements, return their sum
        if (nums.size() <= 3) return accumulate(nums.begin(), nums.end(), 0);

        // initialize answer to any possible value in nums
        int cloest = nums[0] + nums[1] + nums[2];

        // sort: O(nlogn)
        sort(nums.begin(), nums.end());

        // for each number < 0, update current cloest: O(n^2)
        for (int i = 0; i < nums.size() - 1; i++) {
            // prevent first number duplicate
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            // two pointers: O(n)
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // found closer sum
                if (abs(target - sum) < abs(target - cloest)) {
                    cloest = sum;
                    // found exact the same, return
                    if (cloest == target) return cloest;
                }
                sum < target ? left++ : right--;
            }
        }
        return cloest;
    }
};
// @lc code=end
