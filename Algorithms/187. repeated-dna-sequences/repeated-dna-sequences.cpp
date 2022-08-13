/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 *
 * Method: Bit Manipulation
 * Data Structure: Hash Table, String
 *
 */

// @lc encode=start
class Solution {
private:
    // encode each nucleotide to 2 bits
    int encode(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        // encode should never reach here
        assert(false);
    }

public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        if (len < 10) return vector<string>();

        // encode 10 alphabet -> 20 bits -> 2^20 keys
        // Use 2^20 bits to represent each key
        // 1 means yes, 0 means no:
        bitset<1 << 20> once;   // occur once or not
        bitset<1 << 20> twice;  // occur twice or not
        vector<string> ans;
        int key = 0;

        // construct bits for first 10 char
        for (int i = 0; i < 10; i++) key = ((key << 2) | encode(s[i]));
        once.set(key);

        // move one bit forward until end
        int bitmask = 0xfffff;
        for (int i = 10; i < len; i++) {
            key = ((key << 2) | encode(s[i])) & bitmask;
            // don't care if occur more than once
            if (twice[key]) continue;
            // add to answer vector if key has occurred once
            else if (once[key]) {
                ans.push_back(s.substr(i - 9, 10));
                twice.set(key);
            }
            // never meet before
            else {
                once.set(key);
            }
        }

        return ans;
    }
};
// @lc encode=end
