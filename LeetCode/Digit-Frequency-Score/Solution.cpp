1class Solution {
2public:
3    int digitFrequencyScore(int n) {
4        int ans = 0;
5        for (; n > 0; n /= 10) {
6            ans += n % 10;
7        }
8        return ans;
9    }
10};