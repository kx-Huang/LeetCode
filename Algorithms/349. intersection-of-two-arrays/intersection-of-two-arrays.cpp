/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * Method: Iterative Traversal
 * Data Structure: Hash Table
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;

        // if an element found in set:
        //  1. delete element to prevent double count
        //  2. add to answer vector
        for (int e : nums2)  // O(n)
            if (s.erase(e)) ans.push_back(e);

        return ans;
    }
};
// @lc code=end
