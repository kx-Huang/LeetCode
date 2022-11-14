/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 *
 * Method: In-order Traversal
 * Data Structure: Stack
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
class BSTIterator {
private:
    stack<TreeNode*> s;

    void inOrderLeft(TreeNode* node) {
        while (node != nullptr) {
            s.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        inOrderLeft(root);
    }

    int next() {
        TreeNode* curr = s.top();
        s.pop();
        inOrderLeft(curr->right);
        return curr->val;
    }

    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
