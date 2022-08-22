/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 *
 * Method: Separate Chaining
 * Data Structure: Array, List
 *
 */

// @lc code=start
class MyHashSet {
private:
    int prime;
    vector<list<int>> HashSet;

    // use modulo to calculate the index of chain
    inline int hash(int key) {
        return key % prime;
    }

    // return iterator if key found in its chain: O(n), averaged to O(1)
    list<int>::iterator search(int key) {
        int h = hash(key);
        return find(HashSet[h].begin(), HashSet[h].end(), key);
    }

public:
    MyHashSet() : prime(10007), HashSet(prime) {}

    // add key if key is not found in its chain: O(n), averaged to O(1)
    void add(int key) {
        int h = hash(key);
        if (contains(key) == false) HashSet[h].push_back(key);
    }

    // remove key if find in its chain: O(n), averaged to O(1)
    void remove(int key) {
        int h = hash(key);
        auto it = search(key);
        if (it != HashSet[h].end()) HashSet[h].erase(it);
    }

    // check if key is in its chain: O(n), averaged to O(1)
    bool contains(int key) {
        int h = hash(key);
        return search(key) != HashSet[h].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
