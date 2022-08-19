/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * Method: Depth First Search, Backtracking, Divide and Conquer
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
private:
    vector<vector<int>> ans;

    // time & space complexity: O(n^2)
    // valid path can go up to n -> copy n paths takes O(n^2)
    void dfs(TreeNode* root, int target, vector<int>& path) {
        if (root == nullptr) return;

        // insert current value and update target sum
        int val = root->val;
        path.push_back(val);
        target -= val;

        // check if current node is leaf
        if (root->left == nullptr && root->right == nullptr) {
            if (target == 0) ans.push_back(path);
        }
        // recursion for left and right sub-tree
        else {
            dfs(root->left, target, path);
            dfs(root->right, target, path);
        }

        // backtrack to reuse common path
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return this->ans;
    }
};
// @lc code=end
