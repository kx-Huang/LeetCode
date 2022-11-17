/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * Method:
 * Data Structure: cache Table, List
 *
 */

// @lc code=start
class LRUCache {
private:
    int size = 0;
    list<int> priority;  // front (most recent) -> back (least recent)
    unordered_map<int, int> cache;                       // store key-value pair
    unordered_map<int, list<int>::iterator> getItByKey;  // trade space for time

    void prioritize(int key) {
        // key index exists (which means key exists), move to the front.
        if (getItByKey.find(key) != getItByKey.end())
            priority.erase(getItByKey[key]);
        priority.push_front(key);
        getItByKey[key] = priority.begin();
    }

public:
    LRUCache(int capacity) : size(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        prioritize(key);
        return it->second;
    }

    void put(int key, int value) {
        // key not found and cache is full, erase least recent
        if (cache.find(key) == cache.end() && priority.size() == size) {
            getItByKey.erase(priority.back());
            cache.erase(priority.back());
            priority.pop_back();
        }
        // update or add key-value pair
        cache[key] = value;
        // prioritize key
        prioritize(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
