/*
 * @lc app=leetcode id=1846 lang=cpp
 *
 * [1846] Maximum Element After Decreasing and Rearranging
 *
 * Method: Iterative Traversal, Sorting
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // sorting: O(nlogn)
        sort(arr.begin(), arr.end());

        // rearrange array according to the rules: O(n)
        arr[0] = 1;
        int len = arr.size();
        for (int i = 1; i < len; i++)
            if (arr[i] - arr[i - 1] > 1) arr[i] = arr[i - 1] + 1;

        // return the largest element
        return arr[len - 1];
    }
};
// @lc code=end
