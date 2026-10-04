1const int MX = 1000;
2bool isPrime[MX + 1];
3
4auto init = [] {
5    for (int i = 0; i <= MX; ++i) isPrime[i] = true;
6    isPrime[0] = isPrime[1] = false;
7    for (int i = 2; i * i <= MX; ++i) {
8        if (isPrime[i]) {
9            for (int j = i * i; j <= MX; j += i) {
10                isPrime[j] = false;
11            }
12        }
13    }
14    return 0;
15}();
16
17class Solution {
18public:
19    int sumOfPrimesInRange(int n) {
20        int r = 0;
21        int tmp = n;
22        while (tmp) {
23            r = r * 10 + tmp % 10;
24            tmp /= 10;
25        }
26        int low = min(n, r);
27        int high = max(n, r);
28        int ans = 0;
29        for (int x = low; x <= high; ++x) {
30            if (isPrime[x]) ans += x;
31        }
32        return ans;
33    }
34};