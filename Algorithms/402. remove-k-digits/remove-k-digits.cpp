/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 *
 * Method: Greedy
 * Data Structure: Stack, String
 *
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == 0) return num;
        if (num.size() == k) return string("0");

        // we use string as stack
        string ans;

        // iterative traversal: O(n)
        // strategy: choose as small as possible on more significant bit
        for (char digit : num) {
            // if still got chance, replace stack top if current is smaller
            while (ans.size() && k && digit < ans.back()) {
                ans.pop_back();
                k--;
            }
            // if current digit is not smaller or got no chance to replace
            // add to string (pay attention to '0', shouldn't occur at first)
            if (ans.size() || digit != '0') ans.push_back(digit);
        }

        // make sure k digits are removed
        while (ans.size() && k--) ans.pop_back();

        return ans.size() ? ans : string("0");
    }
};
// @lc code=end
