#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        qu1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(qu1.size() != 1) {
            qu2.push(qu1.front());
            qu1.pop();
        }
        int res = qu1.front();
        qu1.pop();
        while(qu2.size() != 0) {
            qu1.push(qu2.front());
            qu2.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res = this->pop();
        qu1.push(res);
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return qu1.size() == 0;
    }

private:
    queue<int> qu1, qu2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */