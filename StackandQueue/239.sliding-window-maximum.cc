#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
    // 实现自己的单调队列
    class MyQueue {
    public:
        deque<int> que;
        // 单调队列中要删除的元素是否使最大值，如果是，就删除，如果不是，不做任何操作
        void pop(int value) {
            if (!que.empty() && value == que.front()) 
                que.pop_front();
        }

        // 插入元素要保证插入之后为单调队列(从大到小)
        void push(int value) {
            while (!que.empty() && value > que.back()) 
                que.pop_back();
            que.push_back(value);
        }

        // 单调队列中使队首始终为最大值
        int front() {
            return que.front();
        }

    };

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            que.push(nums[i]);
        }

        result.push_back(que.front());  // 实现的MyQueue的front()始终返回sliding windows的最大值
        for (int i = k; i < nums.size(); ++i) {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
