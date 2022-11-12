/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    // pre-order traversal return values from smallest to largest
    int findkthSmallest(TreeNode* node, int& k) {
        if (node == nullptr) return -1;
        int prev = findkthSmallest(node->left, k);
        if (k == 0) return prev;
        if (--k == 0) return node->val;
        return findkthSmallest(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return -1;
        return findkthSmallest(root, k);
    }
};
// @lc code=end
