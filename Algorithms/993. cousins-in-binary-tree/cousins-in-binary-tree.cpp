/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
 *
 * Method: Level-order Traversal
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;
        if (root->val == x || root->val == y) return false;

        queue<TreeNode*> q;
        q.push(root);
        bool foundX = false;
        bool foundY = false;

        while (!q.empty()) {
            int n = q.size();
            // in for loop, same level
            for (int i = 0; i < n; i++) {
                // get current node
                TreeNode* cur = q.front();
                q.pop();
                // get children value if have and enqueue children
                int leftVal = -1;
                int rightVal = -1;
                if (cur->left) {
                    leftVal = cur->left->val;
                    q.push(cur->left);
                }
                if (cur->right) {
                    rightVal = cur->right->val;
                    q.push(cur->right);
                }
                // same parent, return false
                if ((leftVal == x && rightVal == y) ||
                    (leftVal == y && rightVal == x))
                    return false;
                // match one, take notes
                if (!foundX && !foundY) {
                    if (leftVal == x || rightVal == x) foundX = true;
                    if (leftVal == y || rightVal == y) foundY = true;
                } else {
                    if (foundX && (leftVal == y || rightVal == y)) return true;
                    if (foundY && (leftVal == x || rightVal == x)) return true;
                }
            }
            if (foundX || foundY) return false;
        }
        return false;
    }
};
// @lc code=end
