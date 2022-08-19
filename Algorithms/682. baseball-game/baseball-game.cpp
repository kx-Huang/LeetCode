/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 *
 * Method: Iterative Traversal
 * Data Structure: Stack
 *
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {
        // use stack to keep track of the records
        stack<int> record;

        // iterative traversal: O(n)
        for (string s : ops) {
            if (s == "C") {
                record.pop();
            } else if (s == "D") {
                record.push(record.top() * 2);
            } else if (s == "+") {
                int num1 = record.top();
                record.pop();
                int num2 = record.top();
                record.push(num1);
                record.push(num1 + num2);
            }
            // number
            else {
                record.push(stoi(s));
            }
        }

        // get sum
        int ans = 0;
        while (!record.empty()) {
            ans += record.top();
            record.pop();
        }

        return ans;
    }
};
// @lc code=end
