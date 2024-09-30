class CustomStack {
public:
    vector<int> stack;
    int top = -1;
    CustomStack(int maxSize) {
        stack.resize(maxSize);
    }
    
    void push(int x) {
        if(top != stack.size() - 1) {
            stack[top + 1] = x;
            top++;
        }
    }
    
    int pop() {
        if(top == -1)
            return -1;
        top--;
        return stack[top + 1];
    }
    
    void increment(int k, int val) {
        if(top == -1)
            return;
        for(int i = 1; i <= min(top + 1, k); i++) {
            stack[i - 1] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */