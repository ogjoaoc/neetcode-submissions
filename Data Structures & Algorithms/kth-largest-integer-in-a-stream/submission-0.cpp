class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> heap;
    KthLargest(int k, vector<int>& nums) {
        this->K = k;
        for (int x : nums) {
            heap.push(x);
            if (heap.size() > k) heap.pop();
        }
    }
    int add(int val) {
        heap.push(val);
        if (heap.size() > K) heap.pop();
        return heap.top();
    }
};
