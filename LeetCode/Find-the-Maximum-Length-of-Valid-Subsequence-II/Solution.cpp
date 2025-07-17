class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        max_len = 0
        for x in range(k):
            freq = [0] * k
            for num in nums:
                num %= k
                freq[num] = freq[(x - num) % k] + 1
                max_len = max(max_len, freq[num])
        return max_len