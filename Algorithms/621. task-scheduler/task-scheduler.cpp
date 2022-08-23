/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * Method: Iterative Traversal
 * Data Structure: Hash Table, Round-robin
 *
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        if (n == 0) return len;

        // use hash table to count the times of each task
        unordered_map<char, int> count;

        // initialize hash table and get the highest task count: O(n)
        int high = 0;
        for (char c : tasks) {
            count[c]++;
            high = max(high, count[c]);
        }

        // group different tasks in a group of n+1
        // put idle if no different task remaining
        // Note: we don't need to fill the last group as the tasks are done
        // e.g.     [A, A, A, B, B, C]  n = 2 (high = 3)
        // group 1: (A, B, C)
        // group 2: (A, B, /)
        // group 3: (A)

        // compute group 1 to "high-1"
        int ans = (high - 1) * (n + 1);
        // compute group "high": O(n)
        for (auto p : count)
            if (p.second == high) ans++;

        // our answer given by grouping is the minimum requirment
        // if we have more tasks to schedule, just return the number of tasks
        return max(len, ans);
    }
};
// @lc code=end
