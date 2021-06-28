#include <vector>
#include <string>
#include <set>
#include <stack>

using std::vector;
using std::string;
using std::set;
using std::stack;

class Solution {
public :
    int evalRPN(vector<string>& tokens) {
        stack<int> st; // 使用栈结构来解题
        set<string> operators{"+", "-", "*", "/"};
        for (auto vi = tokens.begin(); vi != tokens.end(); ++vi) {
            if (operators.find(*vi) != operators.end()) {
                int operand1 = st.top(); st.pop();
                int operand2 = st.top(); st.pop();
                if (*vi == "+") st.push(operand1+operand2);
                if (*vi == "-") st.push(operand2-operand1);
                if (*vi == "*") st.push(operand1*operand2);
                if (*vi == "/") st.push(operand2/operand1);
            } else {
                st.push(stoi(*vi));
            }
        }
        return st.top();
    }
};
