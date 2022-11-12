/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * Method: Divide and Conquer
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
    bool isValid(TreeNode* node, TreeNode* min, TreeNode* max) {
        if (node == nullptr) return true;
        if (max && max->val <= node->val) return false;
        if (min && min->val >= node->val) return false;
        return isValid(node->left, min, node) &&
               isValid(node->right, node, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }
};
// @lc code=end
