/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * Method: Iterative Traversal
 * Data Structure: Stack, String
 *
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        // use stack to save current number and sign
        // stack structure: number -> sign -> number ... -> top
        stack<int> exp;
        exp.push(0);
        int sign = 1;
        int len = s.size();

        // iterative traversal: O(n)
        // current sum is always on stack top
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                exp.push(sign);
                exp.push(0);
                sign = 1;
            } else if (c == ')') {
                int innerSum = exp.top();
                exp.pop();
                int sign = exp.top();
                exp.pop();
                int OuterSum = exp.top();
                exp.pop();
                exp.push(OuterSum + sign * innerSum);
            } else if (isdigit(c)) {
                // get new number
                int num = c - '0';
                for (; i + 1 < len && isdigit(s[i + 1]); i++)
                    num = 10 * num + (s[i + 1] - '0');
                // get current sum
                int curSum = exp.top();
                exp.pop();
                // push new sum
                exp.push(curSum + sign * num);
            }
        }

        return exp.top();
    }
};
// @lc code=end
