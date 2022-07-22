/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum and hash table
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> map;  // prefix_sum: occur_times

        // looking for "short prefix sum" 0 means:
        //     current "long prefix sum" is already a target
        map[0] = 1;

        for (int num : nums) {
            // current "long prefix sum"
            sum += num;
            // if a "short prefix sum" exists, satisfying:
            //     "long prefix sum" - "short prefix sum" == k,
            // then
            //     add occurred times of "short_prefix_sum" to answer
            if (map.find(sum - k) != map.end()) ans += map[sum - k];
            // update occurred time for specific sum
            map[sum]++;
        }
        return ans;
    }
};
// @lc code=end
