// 反转字符串
// 使用双指针法 
// 交换两个变量的值 位运算异或方法 
// a^a = 0    a^0 = a
void reverseString(vector<int>& s) {
    size_t i = 0, j = s.size() - 1;
    while (i < j) {
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];
    }
}