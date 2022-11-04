/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * Method: Breadth First Search
 * Data Structure: Queue
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //  no root
        if (root == nullptr) return vector<vector<int>>();

        TreeNode* cur = root;
        bool levelNeedReverse = false;

        int curLevelNodeLeft = 1;
        int nextLevelNodeLeft = 0;

        vector<int> level;
        vector<vector<int>> ans;

        // queue for level-order traversal
        queue<TreeNode*> q;
        q.push(cur);

        while (!q.empty()) {
            // pop queue get current node
            cur = q.front();
            level.push_back(cur->val);
            q.pop();
            curLevelNodeLeft--;

            // push children in queue and update next level children count
            if (cur->left != nullptr) {
                q.push(cur->left);
                nextLevelNodeLeft++;
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
                nextLevelNodeLeft++;
            }

            // this level is done, reverse traversal results if needed
            if (curLevelNodeLeft == 0) {
                // do reverse
                if (levelNeedReverse == true)
                    reverse(level.begin(), level.end());
                // toggle reverse indicator
                levelNeedReverse = levelNeedReverse ? false : true;
                // plug in level traverse result to ans
                ans.push_back(level);
                // clear current level traversal
                level.clear();
                // move to next level, update children count
                curLevelNodeLeft = nextLevelNodeLeft;
                nextLevelNodeLeft = 0;
            }
        }
        return ans;
    }
};
// @lc code=end
