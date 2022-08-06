/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * Methods: Divide and Conquer
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // recursion for left & right sub-tree
        flatten(root->left);
        flatten(root->right);

        // append left sub-tree to the middle of current node and right sub-tree
        if (root->left) {
            TreeNode* right = root->right;
            root->right = root->left;
            root->left = NULL;
            while (root->right) root = root->right;
            root->right = right;
        }
    }
};
// @lc code=end
