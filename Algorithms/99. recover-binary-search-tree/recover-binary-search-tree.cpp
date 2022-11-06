/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * Method: In-order Traversal
 * Data Structure: Binary Search Tree
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* firstMistake = nullptr;
    TreeNode* secondMistake = nullptr;
    TreeNode* pre = new TreeNode(INT_MIN);

    // in-order traversal： O(n)
    void findMistakeInOrder(TreeNode* cur) {
        if (cur == nullptr) return;

        findMistakeInOrder(cur->left);

        // if previous value is larger than current value, found a mistake
        // e.g. 1, 4, 3, 2, 5
        // mistake: 4 and 2
        // what we compare: [4,3] and [3,2]
        // here 4 is pre, 2 is cur
        if (pre->val > cur->val) {
            if (firstMistake == nullptr) firstMistake = pre;
            if (firstMistake != nullptr) secondMistake = cur;
        }
        pre = cur;

        findMistakeInOrder(cur->right);
    }

public:
    void recoverTree(TreeNode* root) {
        findMistakeInOrder(root);
        swap(firstMistake->val, secondMistake->val);
    }
};
// @lc code=end
