1class Solution {
2public:
3    int maxDistinct(string s) {
4        int ans = 0;
5        int cnt[26]{};
6        for (char c : s) {
7            if (++cnt[c - 'a'] == 1) {
8                ++ans;
9            }
10        }
11        return ans;
12    }
13};