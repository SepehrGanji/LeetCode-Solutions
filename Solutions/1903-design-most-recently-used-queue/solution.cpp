class MRUQueue {
public:
    MRUQueue(int n) {
        this->n = n;
        for(int i = 1 ; i <= n ; i++) qu.push(i);
    }
    
    int fetch(int k) {
        int el = -1;
        for(int i = 1 ; i <= n ; i++) {
            int eee = qu.front(); qu.pop();
            if(i == k) el = eee;
            else st.push(eee);
        }
        while(!st.empty()) {
            int to = st.front(); st.pop();
            qu.push(to);
        }
        qu.push(el);
        return el;
    }

private:
    int n;
    queue<int> st;
    queue<int> qu;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
