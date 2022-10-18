/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 *
 * Method: Iterative Traversal
 * Data Structure: Union-Find Disjoint Set
 *
 */

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // sort: O(nlogn)
        sort(nums.begin(), nums.end());

        int ans = 0;
        int curMax = nums[0];
        // O(n)
        for (int i = 1; i < nums.size(); i++) {
            // if number is smaller, make it to currMax + 1 to avoid duplicates
            if (nums[i] <= curMax) {
                curMax++;
                ans += (curMax - nums[i]);
            }
            // update curMax if number is larger
            else {
                curMax = nums[i];
            }
        }
        return ans;
    }
};
// @lc code=end
