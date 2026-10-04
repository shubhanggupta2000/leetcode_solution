1class Solution {
2public:
3    int maxProduct(int n) {
4        int a = 0, b = 0;
5        for (; n; n /= 10) {
6            int x = n % 10;
7            if (a < x) {
8                b = a;
9                a = x;
10            } else if (b < x) {
11                b = x;
12            }
13        }
14        return a * b;
15    }
16};