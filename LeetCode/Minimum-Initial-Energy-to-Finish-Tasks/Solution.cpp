1class Solution {
2public:
3    int minimumEffort(vector<vector<int>>& tasks) {
4        sort(tasks.begin(), tasks.end(), [&](const auto& a, const auto& b) { return a[0] - a[1] < b[0] - b[1]; });
5        int ans = 0, cur = 0;
6        for (auto& task : tasks) {
7            int a = task[0], m = task[1];
8            if (cur < m) {
9                ans += m - cur;
10                cur = m;
11            }
12            cur -= a;
13        }
14        return ans;
15    }
16};