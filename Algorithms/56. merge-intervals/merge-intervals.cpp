/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * Method: Iterative Traversal, Sorting
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        // sort intervals by left boundry: O(nlogn)
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        // merge if overlap: O(n)
        for (auto p : intervals) {
            if (p[0] > ans.back()[1])
                ans.push_back(p);
            else
                ans.back()[1] = max(ans.back()[1], p[1]);
        }
        return ans;
    }
};
// @lc code=end
