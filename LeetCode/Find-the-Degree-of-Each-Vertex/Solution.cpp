1class Solution {
2public:
3    vector<int> findDegrees(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5        vector<int> ans(n);
6        for (int i = 0; i < n; ++i) {
7            for (int x : matrix[i]) {
8                ans[i] += x;
9            }
10        }
11        return ans;
12    }
13};