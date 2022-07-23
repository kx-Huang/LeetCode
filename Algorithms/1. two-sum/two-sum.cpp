/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * Method: Iterative Traversal
 * Data Structure: Hash Table
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable{make_pair(nums[0], 0)};

        // find the complement for each element: O(n)
        for (int i = 1; i < nums.size(); i++) {
            // get iterator of complement
            auto it = hashtable.find(target - nums[i]);

            // found complement and not the number itself
            if (it != hashtable.end() && it->second != i)
                return {it->second, i};

            // add key-value: number-index pair to hashtable table
            hashtable[nums[i]] = i;
        }
        // code should not reach here
        assert(false);
    }
};
// @lc code=end
