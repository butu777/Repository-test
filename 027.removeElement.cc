class Solution {
    int removeElement(vector<int>& nums, int val) {
        int i = j = 0;
        for ( ; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
}