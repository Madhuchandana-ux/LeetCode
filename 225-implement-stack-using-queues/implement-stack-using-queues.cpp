class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        // Move n - 1 elements from q1 to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topVal = q1.front();
        q1.pop();
        
        // Swap q1 and q2
        swap(q1, q2);
        return topVal;
    }
    
    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topVal = q1.front();
        q2.push(topVal);
        q1.pop();
        
        swap(q1, q2);
        return topVal;
    }
    
    bool empty() {
        return q1.empty();
    }
};