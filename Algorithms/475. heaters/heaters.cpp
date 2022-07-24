/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 *
 * Methods: Two Pointers
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // sort houses and heaters: O(nlogn+mlogm)
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;

        // Two pointers: O(n+m)
        for (int i = 0, j = 0; i < houses.size(); i++) {
            // move to next heater if next one is closer
            while (j + 1 < heaters.size() && abs(heaters[j + 1] - houses[i]) <=
                                                 abs(heaters[j] - houses[i]))
                j++;
            radius = max(abs(heaters[j] - houses[i]), radius);
        }
        return radius;
    }
};
// @lc code=end
