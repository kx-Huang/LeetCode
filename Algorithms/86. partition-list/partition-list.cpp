/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* smallDummyHead = new ListNode();  // dummy head
        ListNode* largeDummyHead = new ListNode();  // dummy head
        ListNode* small = smallDummyHead;
        ListNode* large = largeDummyHead;

        // append small value to small list, large value to large list
        while (head != NULL) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }

        // append large to small
        small->next = largeDummyHead->next;
        large->next = NULL;

        return smallDummyHead->next;
    }
};
// @lc code=end
