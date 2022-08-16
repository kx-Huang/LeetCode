/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * Method: Iterative Traversal
 * Data Structure: Stack, String
 *
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len <= 1) return 0;

        // use stack to save index of parentheses
        stack<int> index;
        // key point: last unmatched index is always on the top of stack
        index.push(-1);
        int ans = 0;

        // traverse string to match parentheses: O(n)
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                // index of '(' is also last unmatched index
                index.push(i);
            } else {
                int top = index.top();
                index.pop();
                // if not match, update last unmatched index
                if (top == -1 || s[top] == ')') index.push(i);
                // if match, then last unmatched index is still at the top
                // no matter it is '(' or ')'
                else
                    ans = max(ans, i - index.top());
            }
        }

        return ans;
    }
};
// @lc code=end
