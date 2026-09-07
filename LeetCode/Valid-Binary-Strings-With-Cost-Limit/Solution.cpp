1class Solution {
2public:
3    vector<string> generateValidStrings(int n, int k) {
4        vector<string> ans;
5        string path;
6
7        auto dfs = [&](this auto&& dfs, int i, int tot) -> void {
8            if (i >= n) {
9                ans.push_back(path);
10                return;
11            }
12
13            path.push_back('0');
14            dfs(i + 1, tot);
15            path.pop_back();
16
17            if ((path.empty() || path.back() == '0') && tot + i <= k) {
18                path.push_back('1');
19                dfs(i + 1, tot + i);
20                path.pop_back();
21            }
22        };
23
24        dfs(0, 0);
25
26        return ans;
27    }
28};