/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * Method: In-order Traversal, Divide and Conquer
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    queue<string> q;

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return string("-");
        return to_string(root->val) + " " + serialize(root->left) + " " +
               serialize(root->right) + " ";
    }

    // Decodes your encoded data to tree.
    void decode(string& data) {
        istringstream code(data);
        string val = "";
        while (code >> val) q.push(val);
    }

    TreeNode* build() {
        // in case string accidentally changed
        if (q.empty()) return nullptr;
        // get current value
        string s = q.front();
        q.pop();

        if (s == "-") return nullptr;

        TreeNode* cur = new TreeNode(stoi(s));
        cur->left = build();
        cur->right = build();
        return cur;
    }

    TreeNode* deserialize(string data) {
        decode(data);
        return build();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
