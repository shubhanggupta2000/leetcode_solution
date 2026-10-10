1class Solution {
2public:
3    int binaryGap(int n) {
4        int ans = 0;
5        for (int pre = 100, cur = 0; n != 0; n >>= 1) {
6            if (n & 1) {
7                ans = max(ans, cur - pre);
8                pre = cur;
9            }
10            ++cur;
11        }
12        return ans;
13    }
14};