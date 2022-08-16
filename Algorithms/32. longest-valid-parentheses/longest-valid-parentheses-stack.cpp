/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * Method: Dynamic Programming
 * Data Structure: String
 *
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len <= 1) return 0;

        // dp[i] means maximum length at postion i
        vector<int> dp(len, 0);
        int ans = 0;

        // initial condition
        dp[0] = 0;
        int unmatched = 0;

        // relationship:
        // if current is '(': increase count for unmatched '('
        // if current is ')':
        //  1. if still have '(' to match before: dp[i] = dp[i-1] + 2
        //      e.g. "())"   dp[2] have nothing to match in "()"
        //      e.g. "(())"  dp[3] = dp[2] + 2 = 2 + 2 = 4
        //  2. if current length is not the whole string: dp[i] += dp[i - dp[i]]
        //     (append with last matched)
        // e.g. "()()"
        //     step 1: "(" + ")"   -> dp[3] = dp[2] + 2 = 2 -> "()"
        //     step 2: "()" + "()" -> dp[3] = 2 + dp[3-2] = 2 + 2 = 4

        // traversal the string from the start to construct dp array: O(n)
        for (int i = 0; i < len; i++) {
            if (s[i] == '(')
                unmatched++;
            else if (unmatched) {
                // increase count for unmatched '('
                dp[i] = dp[i - 1] + 2;
                // append with last matched if current length is not the whole
                if (i - dp[i] > 0) dp[i] += dp[i - dp[i]];
                unmatched--;
            }
            // update current maximum
            ans = max(dp[i], ans);
        }

        return ans;
    }
};
// @lc code=end
