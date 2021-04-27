// 暴力求解法
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		// 暴力解法循环两次
		int minLen = INT32_MAX;
		int length = 0;
		int sum = 0;
		for(int i = 0; i < nums.size(); ++i) {
			sum = 0;
			for(int j = i; j < nums.size(); ++j) {
				sum += nums[j];
				if (sum >= target) {
					length = j - i + 1;
					minLen = minLen > length ? length : minLen;
					break;
				}
			}
		}
		return minLen == INT32_MAX ? 0 : minLen;
	}
};
