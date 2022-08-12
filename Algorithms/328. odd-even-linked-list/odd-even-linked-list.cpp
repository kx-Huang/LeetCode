/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;

        ListNode* oddNode = head;
        ListNode* evenHead = head->next;
        ListNode* evenNode = evenHead;

        // move forward two nodes at a time
        // odd -> (even -> odd)
        while (evenNode && evenNode->next) {
            oddNode->next = evenNode->next;
            oddNode = oddNode->next;
            evenNode->next = oddNode->next;
            evenNode = evenNode->next;
        }
        // append even list to odd list
        oddNode->next = evenHead;
        return head;
    }
};
// @lc code=end
