/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * Method: Iterative Traversal
 * Data Structure: String, Stack
 *
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1) return false;

        stack<char> st;

        // store open brackets in stack and match top with close brackets: O(n)
        for (char c : s) {
            if (c == '(' | c == '{' | c == '[') {
                st.push(c);
            } else {
                // no match
                if (st.empty()) return false;
                // wrong match
                if (c == ')' && st.top() != '(') return false;
                if (c == '}' && st.top() != '{') return false;
                if (c == ']' && st.top() != '[') return false;
                // right match
                st.pop();
            }
        }

        // empty stack means all match, or exists miss match
        return st.empty();
    }
};
// @lc code=end
