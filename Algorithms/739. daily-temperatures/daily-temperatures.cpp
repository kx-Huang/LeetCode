/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * Method: Iterative Traversal
 * Data Structure: Monotonous Stack
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // use monotonous stack to save index of temperatures:
        // the temperatures are guaranteed to be decreasing
        stack<int> right;
        int len = temperatures.size();
        vector<int> ans(len, 0);

        // iterative traversal: O(n)
        for (int i = len - 1; i >= 0; i--) {
            int val = temperatures[i];
            // pop stack until stack top is larger than current or empty
            while (!right.empty() && val >= temperatures[right.top()])
                right.pop();
            // if still exist larger, we find the nearest larger
            if (!right.empty()) ans[i] = right.top() - i;
            // push current to stack for further comparison
            right.push(i);
        }

        return ans;
    }
};
// @lc code=end
