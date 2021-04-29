#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 循环不变量原则：左闭右开
        // 定义二维数组
        vector<vector<int>> res(n, vector<int>(n, 0)); // vector里面每个元素都是vector<int>型，它通过vector<int>(n, 0)初始化
        int startx = 0, starty = 0;     // 设置每次循环的起始位置
        int loop = n / 2;               // 设置总循环次数，如果n=3，循环一次，如果n为4,循环两次，如果n为5,循环2
        int mid = n / 2;                // 当n为奇数的时候，中间位置需要单独赋值
        int count = 1;                  // 用来给每个空格赋值
        int offset = 1;                 // 每次循环左闭右开原则下需要赋值n-offset个
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;
            // 四个循环，左闭右开
            // 填充上行从左到右
            for (j = starty; j < starty + n - offset; ++j) {
                res[i][j] = count++;
            }
            
            // 填充右列从上到下
            for (i = startx; i < startx + n - offset; ++i) {
                res[i][j] == count++;
            }
            //
            // 填充下行从右到左
            for (; j > starty; --j) {
                res[i][j] = count++;
            }

            // 填充左侧从下到上
            for (; i > startx; --i) {
                res[i][j] = count++;
            }

            startx++;
            starty++;
            offset += 2;
        }
        
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};

int main() {
    Solution s;
    s.generateMatrix(3);
    return 0;
}
