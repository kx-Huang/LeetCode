/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;

        // merge all lists as merge sort does: O(nk*logk)
        // list length: n, list number: k
        // recursion depth: O(logk)
        // comparison each recursion: O(nk)
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i)
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            len = (len + 1) / 2;  // update number of lists left
        }

        // the last one list left is the merged list
        return lists.front();
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // divide and conquer
        // simple case: one of the lists is NULL
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        // recursion: merge sub-lists and return the smaller node
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// @lc code=end
