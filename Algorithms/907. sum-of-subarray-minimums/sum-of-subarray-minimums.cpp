/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 *
 * Method: Iterative Traversal
 * Data Structure: Monotonous Stack
 *
 */

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int len = arr.size();

        // find distance to smaller element in nearest previous and future
        // e.g. [3, 7, 8, 4]
        // 1. smaller in nearest previous: [None, 3, 7, 3]
        //    distance to smaller element: [None, 1, 1, 3]
        // 2. smaller in nearest future:   [None, 4, 4, None]
        //    distance to smaller element: [None, 2, 1, None]
        vector<int> previous(len);
        vector<int> future(len);

        // Remarks:
        // 1. we use index -1 to represent "None" in nearest previous,
        //    so initialize distance to "index + 1"
        // 2. we use index "arr.size()" to represent "None" in nearest future,
        //    so initialize distance to "arr.size() - index"
        for (int i = 0; i < len; i++) {
            previous[i] = i + 1;
            future[i] = len - i;
        }

        // use monotonous stack to save index of array:
        // the elements are guaranteed to be decreasing, so stack top is maximum
        stack<int> left;   // "left" corresponds to nearest smaller in previous
        stack<int> right;  // "right" corresponds to nearest smaller in future

        // fill in "previous" and "future" vector with the help of the stacks
        // keep the stack increasing: compare from the largest till find smaller

        // fill in "previous" vector: O(n)
        for (int i = 0; i < len; i++) {
            int val = arr[i];
            // if current element is smaller, drop larger elements in stack
            while (!left.empty() && val <= arr[left.top()]) left.pop();
            // until current element is larger than maximum in previous
            // we find an nearest smaller element in previous, update distance
            if (!left.empty()) previous[i] = i - left.top();
            // don't forget to push current element to stack
            left.push(i);
        }

        // fill in "future" vector: O(n)
        // we do same logic but this time start from the end of the array
        for (int i = len - 1; i >= 0; i--) {
            int val = arr[i];
            // Remark: we must handle case for duplicate elements in array
            // so actually we are finding distance to nearest not-larger element
            // we will find out the reason in comments of the next code snippet
            while (!right.empty() && val < arr[right.top()]) right.pop();
            if (!right.empty()) future[i] = right.top() - i;
            right.push(i);
        }

        // for element "3"
        //  e.g. [2, 9, 7, 8, 3, 4, 6, 1]
        //        |                    |
        //     previous              future
        // - for sub-array containing "3" between (but exclude) "2" and "1"
        //   we have 4 * 3 = 12 different sub-arrays:
        //     e.g. consider following steps for choosing combinations：
        //        1. we must choose "3"
        //        2. we can choose "", "8", "78", "978" from left: 4 choices
        //        3. we can choose "", "4", "46" from right: 3 choices
        //   as a result, we have 3*4=12 choices in total to form sub-arrays
        //   which is exact the previous[i] * future[i]
        // - in this 12 different sub-arrays: the minimum element is "3" itself
        //   so the sum is 12 * 3 = 36
        // - we can do the same thing for all elements in array with same logic
        long long ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < len; i++)
            ans = (ans + (long long)arr[i] * previous[i] * future[i]) % mod;
        return (int)ans;
    }
};
// @lc code=end
