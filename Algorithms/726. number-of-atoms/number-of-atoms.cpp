/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 *
 * Method: Iterative Traversal
 * Data Structure: Stack, Ordered Map, String
 *
 */

// @lc code=start
class Solution {
public:
    string countOfAtoms(string formula) {
        // Use stack to save each factor
        stack<int> factors;
        // Use map to count occurrence and sort by key (not hash table)
        map<string, int> count;
        // current factor (multiplied by every factors after ")")
        int currFactor = 1;
        // current coefficient (appears directly after one element)
        int coef = 1;
        // iterate formula in reverse order: O(n)
        for (int i = formula.size() - 1; i >= 0; i--) {
            char c = formula[i];
            // number
            if (isdigit(c)) {
                int end = i;
                while (i >= 1 && isdigit(formula[i - 1])) i--;
                int number = stoi(formula.substr(i, end - i + 1));
                // number indicating factor: followed by ')'
                if (i >= 1 && formula[i - 1] == ')') {
                    i--;
                    currFactor *= number;  // update current factor
                    factors.push(number);  // push factor to stack
                    continue;
                }
                // number indicating element count: followed by an element
                coef = number;  // to be used when parsing the element
            }
            // lower case alphabet
            else if (islower(c)) {
                int end = i;
                // get alphabet until upper case: start of an element
                while (i >= 0 && !isupper(formula[i])) i--;
                string element = formula.substr(i, end - i + 1);
                count[element] += currFactor * coef;
                coef = 1;  // reset coefficient as current element is done
            }
            // upper case alphabet
            else if (isupper(c)) {
                count[string(1, c)] += currFactor * coef;
                coef = 1;
            }
            // open bracket
            else if (c == '(') {
                // divide current factor by stack top and pop stack top
                // brackets come in pair, stack must not be empty
                currFactor /= factors.top();
                factors.pop();
            }
            // explicit close bracket without coefficient: e.g. (H2O)
            else if (c == ')') {
                // push 1 as factor into stack
                factors.push(1);
            }
        }

        // output map result
        string ans = "";
        for (auto p : count) {
            ans += p.first;
            if (p.second > 1) ans += to_string(p.second);
        }
        return ans;
    }
};
// @lc code=end
