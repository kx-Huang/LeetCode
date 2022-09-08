/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * Method: Greedy, Breadth First Search
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return len - 1;

        int ans = 0;
        int lastReached = 0;  // max index can be reached of last step
        int curReached = 0;   // max index can be reached currently

        // greedy: O(n)
        // move as much as possible in current reachable range
        for (int i = 0; i < len - 1; i++) {
            curReached = max(curReached, i + nums[i]);
            // if we can reach the last index, return step plus one
            if (curReached >= len - 1) return ans + 1;
            // we searched to the maximum last step can reach, move on
            if (i == lastReached) {
                lastReached = curReached;
                ans++;
            }
        }
        // code should never reach here
        // assume always reach the last index.
        assert(false);
    }
};
// @lc code=end
