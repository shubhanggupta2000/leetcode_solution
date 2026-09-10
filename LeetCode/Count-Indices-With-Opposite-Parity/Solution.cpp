1class Solution {
2public:
3    vector<int> countOppositeParity(vector<int>& nums) {
4        int cnt[2] = {0, 0};
5        for (int x : nums) {
6            cnt[x & 1]++;
7        }
8        int n = nums.size();
9        vector<int> ans(n);
10        for (int i = 0; i < n; ++i) {
11            cnt[nums[i] & 1]--;
12            ans[i] = cnt[(nums[i] & 1) ^ 1];
13        }
14        return ans;
15    }
16};