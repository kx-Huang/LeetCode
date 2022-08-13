/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 *
 * Methods: Iterative Traversal
 * Data Structure: Stack, String
 *
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    static bool isNumber(char c) {
        return (c == '-') || isdigit(c);
    }

public:
    NestedInteger deserialize(string s) {
        // use stack to save the NestedInteger
        stack<NestedInteger> st;
        st.push(NestedInteger());  // always in stack as dummy object

        // iterate the string and constrcut the NestedInteger: O(n)
        for (auto it = s.begin(); it != s.end();) {
            auto c = *it;
            // number (pay attention to negative sign '-')
            if (isNumber(c)) {
                // return the next iterator after a number
                auto it_number_end = find_if_not(it, s.end(), isNumber);
                int number = stoi(string(it, it_number_end));
                st.top().add(NestedInteger(number));
                // jump to next character after this number
                it = it_number_end;
            } else {
                // push new NestedInteger instance
                if (c == '[') st.push(NestedInteger());
                // pop and add to stack top: inner data pop first
                else if (c == ']') {
                    NestedInteger inner = st.top();
                    st.pop();
                    st.top().add(inner);
                }
                it++;
            }
        }

        // return first element in dummy object
        return st.top().getList().front();
    }
};
// @lc code=end
