/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * Method: Dynamic Programming
 * Data Structure: Array, Hash Table
 *
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // put the words in wordDict into hash set: O(n)
        unordered_set<string> us;
        for (string word : wordDict) us.insert(word);

        // dp[i] means if first i character of s can be built from dict
        vector<bool> dp(s.size() + 1, false);

        // initial condition: empty string can be built from dict
        dp[0] = true;

        // dynamic programming: O(m*n)
        // relationship: dp[i] = dp[j] && (substring[j~i] in dict?)
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] == true) {
                    if (us.find(s.substr(j, i - j)) != us.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.size()];
    }
};
// @lc code=end
