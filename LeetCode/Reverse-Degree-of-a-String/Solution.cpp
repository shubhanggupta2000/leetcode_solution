1class Solution {
2public:
3    int reverseDegree(string s) {
4        int n = s.length();
5        int ans = 0;
6        for (int i = 1; i <= n; ++i) {
7            int x = 26 - (s[i - 1] - 'a');
8            ans += i * x;
9        }
10        return ans;
11    }
12};