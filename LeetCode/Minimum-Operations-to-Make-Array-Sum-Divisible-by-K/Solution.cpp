class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long total = 0;
        for (int num : nums) {
            total += num;
        }

        int remainder = total % k;
        if (remainder == 0) return 0;

        // Sort nums in descending order to reduce larger numbers first
        sort(nums.rbegin(), nums.rend());

        int operations = 0;
        for (int num : nums) {
            int reduce = min(remainder, num);  // reduce the number as much as needed or possible
            operations += reduce;
            remainder -= reduce;
            if (remainder == 0) break;
        }

        return operations;
    }
};