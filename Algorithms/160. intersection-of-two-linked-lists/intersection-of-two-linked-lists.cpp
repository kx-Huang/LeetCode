/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 *
 * Methods: Iterative Traversal
 * Data Structure: Linked List
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // A = a + common
        // B = b + common
        // (a + common +   b) + common
        // (b   + common + a) + common
        //                    ^
        //                stop here
        ListNode *nodeA = headA, *nodeB = headB;
        while (nodeA != nodeB) {
            nodeA = nodeA ? nodeA->next : headB;
            nodeB = nodeB ? nodeB->next : headA;
        }
        return nodeA;
    }
};
// @lc code=end
