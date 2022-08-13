/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 *
 * Method: Dynamic Programming
 * Data Structure: Min Heap
 *
 */

// @lc code=start

#define p pair<long long, int>

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // 1 has no prime factors
        // therefore all of its prime factors are in the array primes
        if (n == 1) return 1;

        // Optimize: use min heap to keep track on the min value and its index
        vector<long long> dp(n);
        vector<int> pos(primes.size(), 0);
        priority_queue<p, vector<p>, greater<p>> candidates;

        // 0. initial conditions: dp[0] = 1
        dp[0] = 1;
        for (int i = 0; i < primes.size(); i++) candidates.push({primes[i], i});

        for (int i = 1; i < n;) {  // O(n)
            // 1. choose the smallest from candidates as dp[i]
            auto [min, index] = candidates.top();
            candidates.pop();
            // (don't forget to prevent duplicates)
            if (min != dp[i - 1]) dp[i++] = min;
            // 2. update: pos[j]++
            pos[index]++;
            // 3. generate a new ugly number on the index chosen before
            // push into heap: O(logk)
            candidates.push({primes[index] * dp[pos[index]], index});
            // 4. get to step 1 until get n-th ugly number
        }
        return dp[n - 1];
    }
};
// @lc code=end
