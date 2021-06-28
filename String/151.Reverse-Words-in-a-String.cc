#include <iostream>

using namespace std;

class Solution {
public:
        // 1. 去除多余的空格(不要忘记开头和结尾的空格) 最终每个单词间隔一个空格
        // 2. 整体反转
        // 3. 单个反转

        // 1. 去除多余的空格，使用双指针法
        void removeExtraSpaces(string &s) {
            size_t slow = 0, fast = 0;
            int flag = 0; // 表示当前是否是单词
            while (s.size() > 0 && fast < s.size() && s[fast] == ' ') fast++;
            for (; fast < s.size(); ++fast) {
                // 遍历字符串的第一种情况，开头既是单词
                if (fast == 0) {  // 表示开头没有空格，一开始就是单词
                    flag = 1;
                }
                // 遍历字符串的第二种情况，单词前有空格
                if (s[fast] != ' ' && s[fast-1] == ' ') {
                    flag = 1; // 表示进入了单词状态
                    s[slow++] = ' '; // 由于要保留每个单词的之间有一个空格
                }
                // 遍历字符串的第三种情况，到达一个单词尾部
                if (s[fast] == ' ' && s[fast-1] != ' ') {
                    flag = 0; // 表示进入了空格状态
                }
                if (flag == 1) {
                    s[slow++] = s[fast];
                } else {
                    continue;
                }
            }
            s.resize(slow); // slow在最后一次被赋值后++操作，刚好等于字符串长度
        }

        // 2. 整体反转
        void reverse(string& s, size_t start, size_t end) {
            for (size_t i = start, j = end; i < j; i++, j--) {
                swap(s[i], s[j]);
            }
        }

        // 3. 单个反转
        string reverseWords(string s) {
            removeExtraSpaces(s);
            reverse(s, 0, s.size() - 1);
            size_t start = 0;
            size_t end = 0;
            bool entry = 0;
            for (size_t i = 0; i < s.size(); ++i) {
                if (entry == 0 && s[i] != ' ') {
                    entry = 1;
                    start = i;
                } else if (entry == 1 && s[i] == ' ') {
                    entry = 0;
                    end = i - 1;
                    reverse(s, start, end);
                } else if (entry == 1 && i == s.size() - 1 && s[i] != ' ') {
                    end = i;
                    entry = 0;
                    reverse(s, start, end);
                }
            }
            return s;
        }
};

int main(int argc, char ** argv) {
    string s = "  hello world";
    Solution solu;
    solu.removeExtraSpaces(s);
    cout << solu.reverseWords(s) << endl;

}