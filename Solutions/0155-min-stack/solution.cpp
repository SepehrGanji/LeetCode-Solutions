class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {}
    
    void push(int val) {
        int newmin = min(val, this->getMin());
        st.push(make_pair(val, newmin));
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        if(this->st.empty()) return INT_MAX;
        else {
            return st.top().second;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
