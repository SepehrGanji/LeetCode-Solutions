class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {}
    
    void push(int x) {
        this->st1.push(x);
    }

    void copy() {
      while(!this->st1.empty()) {
        this->st2.push(this->st1.top());
        this->st1.pop();
      }
    }
    
    int pop() {
        if(this->st2.empty()) copy();
        int tmp = this->st2.top();
        this->st2.pop();
        return tmp;
    }
    
    int peek() {
        if(this->st2.empty()) copy();
        return this->st2.top();
    }
    
    bool empty() {
        return this->st1.empty() && this->st2.empty();
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
