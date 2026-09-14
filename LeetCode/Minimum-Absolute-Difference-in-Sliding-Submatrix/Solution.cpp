1class Solution {
2public:
3    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
4        int m = grid.size(), n = grid[0].size();
5        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
6        for (int i = 0; i <= m - k; ++i) {
7            for (int j = 0; j <= n - k; ++j) {
8                vector<int> nums;
9                for (int x = i; x < i + k; ++x) {
10                    for (int y = j; y < j + k; ++y) {
11                        nums.push_back(grid[x][y]);
12                    }
13                }
14                ranges::sort(nums);
15                int d = INT_MAX;
16                for (int t = 1; t < nums.size(); ++t) {
17                    if (nums[t] != nums[t - 1]) {
18                        d = min(d, abs(nums[t] - nums[t - 1]));
19                    }
20                }
21                ans[i][j] = (d == INT_MAX) ? 0 : d;
22            }
23        }
24        return ans;
25    }
26};