1class Solution {
2public:
3    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
4        int n = img1.size();
5        map<pair<int, int>, int> cnt;
6        int ans = 0;
7        for (int i = 0; i < n; ++i) {
8            for (int j = 0; j < n; ++j) {
9                if (img1[i][j]) {
10                    for (int h = 0; h < n; ++h) {
11                        for (int k = 0; k < n; ++k) {
12                            if (img2[h][k]) {
13                                ans = max(ans, ++cnt[{i - h, j - k}]);
14                            }
15                        }
16                    }
17                }
18            }
19        }
20        return ans;
21    }
22};