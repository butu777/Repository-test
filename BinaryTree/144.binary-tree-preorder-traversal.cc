#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 两种方法 1. 递归 2. 非递归，栈实现迭代


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归写法
#if 0
class Solution {
public:
    void preTraversal(TreeNode* root, vector<int>& vec) {
        if (root == NULL) return;  // 递归出口
        vec.push_back(root->val);
        preTraversal(root->left, vec);
        preTraversal(root->left, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        preTraversal(root, vec);
        return vec;
    }
};
#endif


// 非递归写法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node != NULL) result.push_back(node->val);
            else continue;
            st.push(node->right);  // FILO 右孩子进栈
            st.push(node->left);   // 后进系拿出，左孩子进栈
        }
        return result;
    }
};
