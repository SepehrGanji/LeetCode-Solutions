class KthLargest {
    priority_queue<int, vector<int>, greater<int>> mh;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto num: nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if(mh.size() < k) {
            mh.push(val);
        } else if(val > mh.top()) {
            mh.pop();
            mh.push(val);
        }
        return mh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
