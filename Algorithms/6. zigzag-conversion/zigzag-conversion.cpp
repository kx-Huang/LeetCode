/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 *
 * Method: Iterative Traversal
 * Data Structure: String
 *
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0) return string("");
        if (numRows == 1) return s;

        // rows for saving intermediate steps
        vector<string> rows(numRows, "");

        // iterative traversal: O(n)
        for (int i = 0, j = 0, up = 0; i < s.size(); i++) {
            rows[j] += s[i];
            if (j == 0) up = 1;
            if (j == numRows - 1) up = 0;
            j = up ? j + 1 : j - 1;
        }

        // output rows to answer string
        string ans = "";
        for (string row : rows) ans += row;
        return ans;
    }
};
// @lc code=end
