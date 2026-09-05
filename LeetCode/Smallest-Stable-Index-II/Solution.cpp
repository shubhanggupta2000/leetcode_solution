1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n = nums.size();
5        vector<int> right(n);
6        right[n - 1] = nums[n - 1];
7
8        for (int i = n - 2; i >= 0; --i) {
9            right[i] = min(right[i + 1], nums[i]);
10        }
11
12        int left = 0;
13        for (int i = 0; i < n; ++i) {
14            left = max(left, nums[i]);
15            if (left - right[i] <= k) {
16                return i;
17            }
18        }
19        return -1;
20    }
21};