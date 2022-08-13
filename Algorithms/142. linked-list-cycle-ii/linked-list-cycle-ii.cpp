/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * Method: Slow & Fast Pointers
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;

        // Slow & Fast Pointers: determint if cycle exists
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            // found cycle
            if (slow == fast) {
                // Floyd’s Cycle Finding Algorithm:
                // step of head to entry = step of meeting to entry
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        // have no cycle: reach nullptr
        return nullptr;
    }
};
// @lc code=end
