/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * Method: Iterative Traversal
 * Data Structure: Monotonous Stack
 *
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // use monotonous stack to save index of heights:
        // the elements are guranteed to be increasing
        stack<int> left;
        stack<int> right;
        int len = heights.size();

        // find the index of the nearest smaller elements in previous and future
        // they form a boundry for a local maximum area
        vector<int> previous(len, -1);
        vector<int> future(len, len);

        // fill in the index of the nearest smaller elements in previous: O(n)
        for (int i = 0; i < len; i++) {
            int val = heights[i];
            while (!left.empty() && val <= heights[left.top()]) left.pop();
            if (!left.empty()) previous[i] = left.top();
            left.push(i);
        }

        // fill in the index of the nearest smaller elements in future: O(n)
        for (int i = len - 1; i >= 0; i--) {
            int val = heights[i];
            while (!right.empty() && val <= heights[right.top()]) right.pop();
            if (!right.empty()) future[i] = right.top();
            right.push(i);
        }

        // calculate the maximum area
        int ans = 0;
        for (int i = 0; i < len; i++)
            ans = max(ans, (future[i] - previous[i] - 1) * heights[i]);

        return ans;
    }
};
// @lc code=end
