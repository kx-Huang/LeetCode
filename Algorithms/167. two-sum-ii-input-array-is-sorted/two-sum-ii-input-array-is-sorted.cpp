/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // two pointers method
        int left = 0;
        int right = numbers.size() - 1;

        // compare the sum and shrink the range
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
                return {left + 1, right + 1};
            else if (sum < target)
                left++;
            else
                right--;
        }
        // code should not reach here
        assert(false);
    }
};
// @lc code=end
