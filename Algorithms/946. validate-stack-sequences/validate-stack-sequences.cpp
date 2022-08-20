/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 *
 * Method: Iterative Traversal, Greedy Algorithm
 * Data Structure: Stack
 *
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size();
        stack<int> nums;

        // iterate through push operations: O(n)
        for (int i = 0, j = 0; i < len && j < len; i++) {
            nums.push(pushed[i]);
            // for each push, try to pop as many element as possible
            for (; !nums.empty() && nums.top() == popped[j]; j++) nums.pop();
        }

        // if final stack is empty, then the operations are valid
        return nums.empty();
    }
};
// @lc code=end
