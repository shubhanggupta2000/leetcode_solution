1class Solution {
2public:
3    int countTriples(int n) {
4        int ans = 0;
5        for (int a = 1; a < n; ++a) {
6            for (int b = 1; b < n; ++b) {
7                int x = a * a + b * b;
8                int c = static_cast<int>(sqrt(x));
9                if (c <= n && c * c == x) {
10                    ++ans;
11                }
12            }
13        }
14        return ans;
15    }
16};