1class Solution {
2public:
3    long long countCommas(long long n) {
4        long long ans = 0;
5        for (long long x = 1000; x <= n; x *= 1000) {
6            ans += n - x + 1;
7        }
8        return ans;
9    }
10};