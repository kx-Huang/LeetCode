/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 *
 * Methods: Iterative Traversal
 * Data Structure: Stack, String
 *
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // use stack to save index of open parentheses
        stack<int> st;

        // pop stack if match else marked as '*' (to delete afterwards): O(n)
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty())
                    s[i] = '*';
                else
                    st.pop();
            }
        }

        // if open parentheses are not closed
        while (!st.empty()) {
            int index = st.top();
            st.pop();
            s[index] = '*';
        }

        // remove all * and erase extra spaces
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
// @lc code=end
