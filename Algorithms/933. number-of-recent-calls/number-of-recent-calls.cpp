/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 *
 * Method: Iterative Traversal
 * Data Structure: Queue
 *
 */

// @lc code=start
class RecentCounter {
private:
    queue<int> time;

public:
    RecentCounter() {}

    int ping(int t) {
        time.push(t);
        // keep poping time stamp if expiring: O(n)
        while (time.front() < t - 3000) time.pop();
        return time.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
