#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {}

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int size = que1.size();
        size--;
        while (size--) {     // 把除了最新加入的元素的其他元素都转入辅助队列
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front();
        que1.pop();

        que1 = que2;        // 把辅助队列中的元素还原到que1,并删除辅助队列中的元素
        while (!que2.empty()) {
            que2.pop();
        }

        return result;
    }

    int top() {
        return que1.back();
    }

    bool empty() {
        return que1.empty();
    }
};
