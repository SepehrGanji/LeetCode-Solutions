class PhoneDirectory {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> mmd;
    
    PhoneDirectory(int maxNumbers) {
        for(int i = 0 ; i < maxNumbers ; i++) {
            pq.push(i);
            mmd.push_back(true);
        }
    }
    
    int get() {
        if(pq.empty()) return -1;
        int el = pq.top(); pq.pop();
        mmd[el] = false;
        return el;
    }
    
    bool check(int number) {
        return mmd[number];
    }
    
    void release(int number) {
        if(mmd[number] == true) return;
        mmd[number] = true;
        pq.push(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
