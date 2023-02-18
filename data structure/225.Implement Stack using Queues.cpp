class MyStack {
private:
    int top_id;
    int *data;
public:
    MyStack() {
        top_id = -1;
        data = new int[100];
    }
    
    void push(int x) {
        top_id += 1;
        data[top_id] = x;
    }
    
    int pop() {
        if (empty()) return INT_MIN;
        int tmp = data[top_id];
        top_id -= 1;
        return tmp;
    }
    
    int top() {
        if (empty()) return INT_MIN;
        return data[top_id]; 
    }
    
    bool empty() {
        if (top_id == -1) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
    
    int pop() {
        int tmp = q.front();
        q.pop();
        return tmp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};