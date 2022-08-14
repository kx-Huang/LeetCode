/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * Method: Iterative Traversal
 * Data Structure: String
 *
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        // this problem description is vague, so
        // following logic is only considered to pass the test
        long ans = 0;
        int sign = 1;
        int i = 0;  // iterative traversal: O(n)

        // remove leading whitespaces
        while (s[i] == ' ') i++;

        // get sign
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            sign = 1;
            i++;
        }

        // get number (don't forget to prevent overflow)
        while ('0' <= s[i] && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            if (ans * sign >= INT_MAX) return INT_MAX;
            if (ans * sign <= INT_MIN) return INT_MIN;
            i++;
        }

        // return answer
        return ans * sign;
    }
};
// @lc code=end
