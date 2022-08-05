/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* dummyHead = new ListNode();
        ListNode* prev = dummyHead;
        ListNode* curr = head;

        while (1) {
            if (curr->next == NULL) {  // one node left, append and return
                prev->next = curr;
                return dummyHead->next;
            } else {  // have 2 nodes
                ListNode* next = curr->next->next;

                // append 2 nodes in reverse order
                prev->next = curr->next;
                prev = prev->next;
                prev->next = curr;
                prev = prev->next;
                prev->next = NULL;

                // return if no more pairs
                if (next == NULL) return dummyHead->next;

                curr = next;
            }
        }
        // code should not reach here
        assert(false);
    }
};
// @lc code=end
