/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * Method: Iterative Traversal
 * Data Structure: String
 *
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string("");

        // get min length to prevent overflow
        int minLen = strs[0].size();
        for (string str : strs)
            minLen = str.size() < minLen ? str.size() : minLen;

        string ans = "";

        // iterative traversal: O(m*n)
        for (int i = 0; i < minLen; i++) {
            char c = strs[0][i];
            for (int j = 0; j < strs.size(); j++)
                // return immediately it not the same
                if (strs[j][i] != c) return ans;
            ans += c;
        }

        return ans;
    }
};
// @lc code=end
