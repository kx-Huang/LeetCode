/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * Method: Iterative Traversal
 * Data Structure: Stack
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // use stack to save index
        // the temperature is guaranteed to be increasing from stack top
        stack<int> s;
        int len = temperatures.size();
        vector<int> ans(len, 0);

        // iterative traversal: O(n)
        // keep pushing smaller temperature in stack, make stack top smallest
        // update answer vector if meet larger one
        for (int i = 0; i < len; i++) {
            if (s.empty()) {
                s.push(i);
                continue;
            }
            while (!s.empty()) {
                int idx = s.top();
                // if temperature is smaller than the smallest one (stack top)
                if (temperatures[i] <= temperatures[idx]) break;
                // else found the first larger temperature
                ans[idx] = i - idx;
                s.pop();
            }
            s.push(i);
        }

        return ans;
    }
};
// @lc code=end
