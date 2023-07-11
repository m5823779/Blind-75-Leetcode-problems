class MyQueue {
private:
    stack<int> s;
    stack<int> buffer;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        int size = s.size();
        for (int i = 0; i < size; i++) {
            buffer.push(s.top());
            s.pop();
        }
        s.push(x);
        for (int i = 0; i < size; i++) {
            s.push(buffer.top());
            buffer.pop();
        }
    }
    
    int pop() {
        int tmp = s.top();
        s.pop();
        return tmp;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
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