class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int el = peek();
        st2.pop();
        return el;
    }
    
    int peek() {
        if(st2.empty()) norm();
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
    
    void norm() {
        while(!st1.empty()) {
            int el = st1.top(); st1.pop();
            st2.push(el);
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
