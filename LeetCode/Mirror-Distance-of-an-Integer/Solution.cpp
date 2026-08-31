class Solution {
public:
    int reverse(int n) {
        int r;
        for (r = 0; n; n /= 10)
            r = r * 10 + n % 10;
        return r;
    }

    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};