/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& i,
                    int left, int right) {
        if (left > right) return nullptr;
        // find j where inorder[j] equals to preorder[i]
        int j = left;
        // can be optimized with hash table
        while (inorder[j] != preorder[i]) j++;
        // construct current node
        TreeNode* cur = new TreeNode(inorder[j]);
        // move to next node in preorder
        i++;
        cur->left = build(preorder, inorder, i, left, j - 1);
        cur->right = build(preorder, inorder, i, j + 1, right);
        return cur;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size();
        int n = inorder.size();
        if (m != n || m == 0) return nullptr;
        int curIdx = 0;
        return build(preorder, inorder, curIdx, 0, n - 1);
    }
};
// @lc code=end
