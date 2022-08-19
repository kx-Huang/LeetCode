/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * Method: Iterative Traversal
 * Data Structure: Stack, String
 *
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        // use stack to save directory name by level
        stack<string> name;
        int len = path.size();

        // iterative traversal: O(n)
        for (int i = 0; i < len; i++) {
            if (path[i] == '/') continue;

            // get token separated by '/'
            string token = "";
            for (; i < len && path[i] != '/'; i++) token += path[i];

            if (token == ".") {
                continue;
            } else if (token == "..") {
                if (!name.empty()) name.pop();
            } else {
                name.push(token);
            }
        }

        // output stack to form the simplified path: O(n)
        if (name.empty()) return string("/");
        string ans = "";
        while (!name.empty()) {
            ans = "/" + name.top() + ans;
            name.pop();
        }
        return ans;
    }
};
// @lc code=end
