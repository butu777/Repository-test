#include <iostream>
#include <stack>

using namespace std;

class Solution {
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            // 遇到左括号，则压入对应的右括号
            if (s[i] == '(')  st.push(')');
            else if (s[i] == '[')  st.push(']');
            else if (s[i] == '{')  st.push('}');
            // 如果栈空，说明之前遇到的都是右括号，false
            // 如果栈顶元素!=当前右括号(因为左括号的情况会压栈)，false
            else if (st.empty() || st.top() != s[i]) return false;
            // 
            else st.pop();
        }
        // 遍历结束之后如果栈为空就代表括号valid；
        return st.empty();
    }
};

