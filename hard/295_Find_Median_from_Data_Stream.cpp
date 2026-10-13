class MedianFinder {
    priority_queue<int> maxHeap; // ordered list에서 n/2 위치보다 작은 element 담는 queue
    priority_queue<int, vector<int>, greater<int>> minHeap; // ordered list에서 n/2 위치보다 큰 element 담는 queue
    // ex. dataStream = {1, 2, 3, 4}
    // maxHeap = {2, 1}
    // minHeap = {3, 4}
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxHeap.size() == minHeap.size()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }

        if (!maxHeap.empty() && minHeap.top() < maxHeap.top()) {
            int a = minHeap.top(); minHeap.pop();
            int b = maxHeap.top(); maxHeap.pop();
            minHeap.push(b);
            maxHeap.push(a);
        }
    }
    
    double findMedian() {
        if (minHeap.size() != maxHeap.size()) return minHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */