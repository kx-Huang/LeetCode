/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        int count = 1;
        ListNode dummyHead = ListNode();
        dummyHead.next = head;
        ListNode* prev = &dummyHead;
        ListNode* curr = head;
        ListNode* target = nullptr;

        // count node to determine reverse rounds
        while (curr = curr->next) count++;

        // do reverse count/k rounds
        //
        // original: ... -> (A -> B -> C -> ... -> I -> J) -> ...
        //            ^      ^    ^                     ^
        //          prev   curr target      =>        target
        //
        // target: insert node B
        //       [0]  ... ->       A -> B -> C  -> ...
        //             ^           ^    ^
        //            prev        curr target
        //       [1]  ... ->      (A      -> C) -> ...
        //       [2]        (B  -> A)     -> C  -> ...
        //       [3] (... -> B) -> A      -> C  -> ...
        //       [4]  ... -> B  -> A      -> C  -> ...
        //             ^           ^         ^
        //            prev        curr     target

        for (int i = 0; i < count / k; i++) {
            curr = prev->next;
            target = curr->next;
            // reverse k sub-list
            for (int j = 1; j < k; j++) {   // k-1 node to insert
                curr->next = target->next;  // [1]
                target->next = prev->next;  // [2]
                prev->next = target;        // [3]
                target = curr->next;        // [4]
            }
            prev = curr;  // next sub-list
        }
        return dummyHead.next;
    }
};
// @lc code=end
