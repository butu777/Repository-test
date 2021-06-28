#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue() {}

    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        if(stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek() {
        int res = this->pop();  // 如何取元素，使用pop成员函数取队首元素，但这里只是访问，所以需要放回
        stOut.push(res);
        return res;
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }

};
