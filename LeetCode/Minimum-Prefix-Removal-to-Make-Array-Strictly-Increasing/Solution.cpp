1class Solution {
2public:
3    int minimumPrefixLength(vector<int>& nums) {
4        for (int i = nums.size() - 1; i; --i) {
5            if (nums[i - 1] >= nums[i]) {
6                return i;
7            }
8        }
9        return 0;
10    }
11};