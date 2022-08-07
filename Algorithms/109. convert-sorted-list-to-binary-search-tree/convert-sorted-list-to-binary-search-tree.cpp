/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * Methods: Depth First Search, Divide and Conquer
 * Data Structure: Linked List, Tree
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* current = NULL;

    // in-order traversal
    // Time complexity: O(n), list is move forward one step each recursion
    // Space complexity: O(logn) for recursion stack
    TreeNode* buildBST(int left, int right) {
        if (left >= right) return NULL;

        TreeNode* node = new TreeNode();
        int mid = left + (right - left) / 2;

        // build left then right sub-tree
        node->left = buildBST(left, mid);
        node->val = current->val;
        current = current->next;
        node->right = buildBST(mid + 1, right);

        return node;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        this->current = head;
        int count = 0;
        // count number of nodes
        for (ListNode* it = head; it; it = it->next) count++;
        return buildBST(0, count);
    }
};
// @lc code=end
