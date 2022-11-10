/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * Method: Breadth First Search
 * Data Structure: Binary Tree, Queue
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // get current level children size
            int n = q.size();
            vector<int> curLevel;
            for (int i = 0; i < n; i++) {
                // dequeue add to current level traversal result
                TreeNode* cur = q.front();
                q.pop();
                curLevel.push_back(cur->val);
                // enqueue childen for next level traversal
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            // push current level traversal results to return vector
            res.push_back(curLevel);
        }

        return res;
    }
};
// @lc code=end
