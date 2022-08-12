/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 *
 * Methods: Reservoir Sampling
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
private:
    ListNode* head = nullptr;

public:
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        // Mathematical Induction to prove equal probability to be chosen
        // 1 node:  P(X1)=1
        // 2 nodes: P(X1)=P(X2)=1/2
        // Assume n nodes: P(X1)=P(X2)=...=P(Xn)=1/n
        // n+1 nodes:
        //      1) Choose n+1: P(X_n+1) = 1/(n+1) by modular
        //      2) For k=1,2,...,n:
        //          P(Xk) =  n/(n+1) (not replaced by n+1)
        //                 * 1/n     (chosen in last round)
        //  So P(X) = 1/(n+1) (Q.E.D.)
        int ans = 0;
        ListNode* it = this->head;
        for (int i = 1; it != nullptr; i++, it = it->next)
            if (rand() % i == 0) ans = it->val;  // P(x_n+1)=1/(x+1)
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end
