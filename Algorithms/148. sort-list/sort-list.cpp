/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * Methods: Divide and Conquer
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        // Slow & Fast Pointers
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // divide into two lists
        ListNode* firstHalf = head;
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        // recursion merge the divided lists: O(nlogn)
        return mergeTwoLists(sortList(firstHalf), sortList(secondHalf));
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummyHead = ListNode();
        ListNode* cur = &dummyHead;

        // traverse two lists and append smaller node
        for (; l1 && l2; cur = cur->next) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
        }

        // append the remaining list to the merged list
        if (l1)
            cur->next = l1;
        else
            cur->next = l2;

        return dummyHead.next;
    }
};
// @lc code=end
