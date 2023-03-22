class MinStack {
private:
    vector<int> data;
    vector<int> min_index;
public:
    MinStack() {}
    
    void push(int val) {
        data.push_back(val);
        if (min_index.empty() || val < data[min_index.back()]) {
            min_index.push_back(data.size() - 1);
        }
        else {
            min_index.push_back(min_index.back());
        }
    }
    
    void pop() {
        data.pop_back();
        min_index.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return data[min_index.back()];
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


class MinStack {
private:
    stack<int> data;
    stack<int> min_val;
public:
    MinStack() {}
    
    void push(int val) {
        data.push(val);
        if (min_val.empty() || val <= getMin()) {
            min_val.push(val);
        }
    }
    
    void pop() {
        if (data.top() == getMin()) {
            min_val.pop();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_val.top();
    }
};


class MinStack {
private:
    stack<int> data;
    stack<int> min_data;
public:
    MinStack() {}
    
    void push(int val) {
        data.push(val);
        if (min_data.empty() || val < min_data.top()) {
            min_data.push(val);
        }
        else {
            min_data.push(min_data.top());
        }
    }
    
    void pop() {
        min_data.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_data.top();
    }
};