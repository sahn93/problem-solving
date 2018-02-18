class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk, minstk;
    MinStack() {
    }
    
    void push(int x) {
        stk.push(x);
        if (minstk.empty() || minstk.top() >= x)
            minstk.push(x);
    }
    
    void pop() {
        if (minstk.top() == stk.top())
            minstk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
