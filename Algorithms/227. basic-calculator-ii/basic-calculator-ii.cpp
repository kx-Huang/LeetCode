/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * Method: Iterative Traversal
 * Data Structure: String
 *
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        istringstream iss('+' + s + "+");

        // Compare with LeetCode 224: Basic Calculator
        //  - this problem can calculate the current result when parsing
        //  - no need of stack since no nested parenthese structure
        char op;
        int curAns = 0;
        int num = 0;
        int ans = 0;

        // iterative traversal: O(n)
        // keep track of current sum:
        //  1. '*' and '/' followed by number: update current sum
        //  2. '+' and '-' followed by number:
        //      - update current sum to total sum
        //      - then update current sum
        while (iss >> op) {
            if (op == '+' || op == '-') {
                ans += curAns;
                curAns = 0;
                iss >> num;
                curAns = (op == '+') ? num : -num;
            } else {
                iss >> num;
                if (op == '*')
                    curAns *= num;
                else if (op == '/')
                    curAns /= num;
            }
        }

        return ans;
    }
};
// @lc code=end
