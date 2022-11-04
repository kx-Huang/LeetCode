/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * Method: Two Pointers
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // start from right-most side as nums1 will not be resized
        // for comparing
        int i = m - 1;  // nums1 = [1,2,3,0,0,0], m = 3, i = 2
        int j = n - 1;  // nums2 = [2,5,6], n = 3, j = 2
        // for inserting
        int a = m + n - 1;  // start from index 5

        // O(m+n)
        while (i >= 0 && j >= 0) {
            // start comparing
            if (nums2[j] > nums1[i])
                nums1[a--] = nums2[j--];
            else
                nums1[a--] = nums1[i--];
        }

        // if nums2 has something left, copy the rest into nums1
        while (j >= 0) nums1[a--] = nums2[j--];
    }
};
// @lc code=end
