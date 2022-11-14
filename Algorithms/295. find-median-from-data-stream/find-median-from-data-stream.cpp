/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * Method: Two Heaps
 * Data Structure: Heap
 *
 */

// @lc code=start
class MedianFinder {
private:
    priority_queue<int> lowerHalf;
    priority_queue<int, vector<int>, greater<int>> upperHalf;

public:
    MedianFinder() {}

    // O(logn)
    void addNum(int num) {
        lowerHalf.push(num);
        upperHalf.push(lowerHalf.top());
        lowerHalf.pop();
        if (upperHalf.size() > lowerHalf.size()) {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }

    // O(1)
    double findMedian() {
        return lowerHalf.size() == upperHalf.size()
                   ? (lowerHalf.top() + upperHalf.top()) / 2.0
                   : lowerHalf.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
