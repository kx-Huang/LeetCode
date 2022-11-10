/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * Method: Divide and Conquer
 * Data Structure: Binary Tree
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
    int maxSum = INT_MIN;

    int findMaxPathSum(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftSum = max(findMaxPathSum(node->left), 0);
        int rightSum = max(findMaxPathSum(node->right), 0);
        // 1. current node as parent (path fixed, compare and update)
        int curSum = node->val + leftSum + rightSum;
        maxSum = max(maxSum, curSum);
        // 2. current node as child (path not fixed, keep searching)
        return node->val + max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        findMaxPathSum(root);
        return maxSum;
    }
};
// @lc code=end
