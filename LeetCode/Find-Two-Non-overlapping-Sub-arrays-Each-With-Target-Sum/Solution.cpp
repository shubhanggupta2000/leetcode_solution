1class Solution {
2public:
3    int minSumOfLengths(vector<int>& arr, int target) {
4        unordered_map<int, int> d;
5        d[0] = 0;
6        int s = 0, n = arr.size();
7        int f[n + 1];
8        const int inf = 1 << 30;
9        f[0] = inf;
10        int ans = inf;
11        for (int i = 1; i <= n; ++i) {
12            int v = arr[i - 1];
13            s += v;
14            f[i] = f[i - 1];
15            if (d.count(s - target)) {
16                int j = d[s - target];
17                f[i] = min(f[i], i - j);
18                ans = min(ans, f[j] + i - j);
19            }
20            d[s] = i;
21        }
22        return ans > n ? -1 : ans;
23    }
24};