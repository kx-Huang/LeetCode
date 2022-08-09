/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * Methods: Dynamic Programming
 * Data Structure: String, Array
 *
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len <= 1) return s;

        // Dynamic Programming: O(n^2)
        vector<vector<bool>> dp(len, vector<bool>(len, false));

        // use sub-string length and start index to get sub-string
        int maxLen = 1;
        int startIdx = 0;

        // initialize dp[i][j] (i ≤ j): O(n^2)
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
            if (i == len - 1) break;
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                maxLen = 2;
                startIdx = i;
            }
        }

        // expand dp array and update longest palindrome: O(n^2)
        // due to i<=j, we should decrease i each iteration with j increased
        for (int i = len - 3; i >= 0; i--) {
            for (int j = i + 2; j < len; j++) {
                // a palindrome with the same element appended left and
                // right is still a palindrome
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    // update max length if longer
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        startIdx = i;
                    }
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
};
// @lc code=end
