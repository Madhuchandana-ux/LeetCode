class CustomStack {
private:
    vector<int> stack;
    int capacity;

public:
    CustomStack(int maxSize) {
        capacity = maxSize;
    }
    
    void push(int x) {
        if (stack.size() < capacity) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if (stack.empty()) return -1;
        int topVal = stack.back();
        stack.pop_back();
        return topVal;
    }
    
    void increment(int k, int val) {
        int limit = min((int)stack.size(), k);
        for (int i = 0; i < limit; i++) {
            stack[i] += val;
        }
    }
};