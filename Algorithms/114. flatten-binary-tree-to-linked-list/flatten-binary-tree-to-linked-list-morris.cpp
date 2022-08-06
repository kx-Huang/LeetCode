/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * Methods: Morris Traversal
 * Data Structure: Tree
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(NULL), right(NULL) {}
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* pre = NULL;  // for finding predecessor of current node

        while (curr) {
            if (curr->left) {
                // find predecessor
                pre = curr->left;
                while (pre->right) pre = pre->right;

                // append right sub-tree to the predecessor of current node
                // append left sub-tree to the right child of current node
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
// @lc code=end
