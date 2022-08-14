/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 *
 * Method: Iterative Traversal
 * Data Structure: Stack, String
 *
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        // we can use string as stack without actually using stack
        string ans;

        // iterative traversal: O(n)
        for (char c : s) {
            // cancell out if two characters are the same
            if (ans.size() > 0 && ans.back() == c)
                ans.pop_back();
            else
                ans.push_back(c);
        }

        return ans;
    }
};
// @lc code=end
