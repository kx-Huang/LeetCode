/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * Methods: Slow & Fast Pointers
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode* mid = findMid(head);
        ListNode* secondHalfReverse = reverseList(mid);
        return compareList(head, secondHalfReverse);
    }

private:
    bool compareList(ListNode* head1, ListNode* head2) {
        while (head1 != NULL && head2 != NULL) {
            if (head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;  // save previous node
        ListNode* curr = head;
        ListNode* next = NULL;  // save next node
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* findMid(ListNode* head) {
        // Slow & Fast Pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        return slow;
    }
};
// @lc code=end
