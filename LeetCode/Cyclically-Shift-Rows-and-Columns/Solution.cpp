1class Solution {
2public:
3    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
4        vector<vector<int>> t(n, vector<int>(n));
5        for (int i = 0; i < n; i++) {
6            for (int j = 0; j < n; j++) {
7                t[i][(j - rowShift[i] + n) % n] = grid[i][j];
8            }
9        }
10        vector<vector<int>> ans(n, vector<int>(n));
11        for (int j = 0; j < n; j++) {
12            for (int i = 0; i < n; i++) {
13                ans[(i - colShift[j] + n) % n][j] = t[i][j];
14            }
15        }
16        return ans;
17    }
18};