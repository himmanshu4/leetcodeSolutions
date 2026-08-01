class MyStack {
private:
    queue<int> popQueue;
    queue<int> stagingQueue;
    // drain the popQueue and move stuff to staging queue except the last
    // element.
    void drainPopQueue() {
        while (popQueue.size() > 1) {
            int newP = popQueue.front();
            popQueue.pop();
            stagingQueue.push(newP);
        }
    }

public:
    MyStack() {}

    void push(int x) {
        popQueue.push(x);
        drainPopQueue();
    }

    int pop() {
        int poppedValue = popQueue.front();
        popQueue.pop();
        swap(popQueue,stagingQueue);
        drainPopQueue();
        return poppedValue;
    }

    int top() { return popQueue.front(); }

    bool empty() { return popQueue.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */