1class Solution {
2public:
3    int distinctSubseqII(string s) {
4        const int mod = 1e9 + 7;
5        int f[26]{};
6        for (char& c : s) {
7            int x = 1;
8            for (int v : f) {
9                x = (x + v) % mod;
10            }
11            f[c - 'a'] = x;
12        }
13        int ans = 0;
14        for (int v : f) {
15            ans = (ans + v) % mod;
16        }
17        return ans;
18    }
19};