/*
 * @lc app=leetcode id=2104 lang=cpp
 *
 * [2104] Sum of Subnumsay Ranges
 *
 * Method: Iterative Traversal
 * Data Structure: Monotonous Stack
 *
 */

// @lc code=start
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // please refer to LeetCode 907 for detailed explanations
        int n = nums.size();
        vector<int> minPrev(n), minNext(n), maxPrev(n), maxNext(n);
        stack<int> minLeft, minRight, maxLeft, maxRight;

        for (int i = 0; i < n; i++) {
            minPrev[i] = i + 1;
            maxPrev[i] = i + 1;
            minNext[i] = n - i;
            maxNext[i] = n - i;
        }

        for (int i = 0; i < n; i++) {
            while (!minLeft.empty() && nums[minLeft.top()] >= nums[i])
                minLeft.pop();
            if (!minLeft.empty()) minPrev[i] = i - minLeft.top();
            minLeft.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!minRight.empty() && nums[minRight.top()] > nums[i])
                minRight.pop();
            if (!minRight.empty()) minNext[i] = minRight.top() - i;
            minRight.push(i);
        }

        for (int i = 0; i < n; i++) {
            while (!maxLeft.empty() && nums[maxLeft.top()] <= nums[i])
                maxLeft.pop();
            if (!maxLeft.empty()) maxPrev[i] = i - maxLeft.top();
            maxLeft.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!maxRight.empty() && nums[maxRight.top()] < nums[i])
                maxRight.pop();
            if (!maxRight.empty()) maxNext[i] = maxRight.top() - i;
            maxRight.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ((long long)maxPrev[i] * maxNext[i] -
                    (long long)minPrev[i] * minNext[i]) *
                   nums[i];
        }
        return sum;
    }
};
// @lc code=end
