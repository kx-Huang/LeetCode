/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * Methods: Iterative Traversal
 * Data Structure: Linked List, Min Heap
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
        ListNode* dummyNode = new ListNode();
        ListNode* curr = dummyNode;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // push all list head into min heap
        for (auto list : lists)
            if (list) pq.push(list);

        // pop min node and push new node if exists: O(nlogk)
        // maximum k node in min heap: O(logk)
        // average n node per link list: O(n)
        while (!pq.empty()) {
            auto minNode = pq.top();
            pq.pop();
            if (minNode->next) pq.push(minNode->next);
            curr->next = minNode;
            curr = curr->next;
        }
        return dummyNode->next;
    }

private:
    // compare value of two nodes
    struct cmp {
        bool operator()(const ListNode* node1, const ListNode* node2) {
            return node1->val > node2->val;
        }
    };
};
// @lc code=end
