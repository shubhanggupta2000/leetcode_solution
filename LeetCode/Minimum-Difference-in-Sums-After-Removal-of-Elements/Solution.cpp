class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        N = len(nums)
        n = N // 3
        min_sums = [0] * (N + 1)
        max_sums = [0] * (N + 1)

        max_heap_l = []
        sum_l = 0

        for i in range(N):
            heapq.heappush(max_heap_l, -nums[i])
            sum_l += nums[i]

            if len(max_heap_l) > n:
                removed = -heapq.heappop(max_heap_l)
                sum_l -= removed 

            if len(max_heap_l) == n:
                min_sums[i + 1] = sum_l

        min_heap_r = []
        sum_r = 0

        for i in range(N-1, -1, -1):
            heapq.heappush(min_heap_r, nums[i])
            sum_r += nums[i]

            if len(min_heap_r) > n:
                removed = heapq.heappop(min_heap_r)
                sum_r -= removed  

            if len(min_heap_r) == n:
                max_sums[i] = sum_r
        
        

        # print(max_sums)
        # print(min_sums)

        min_diff = float("inf")

        for i in range(n, 2*n + 1):

            min_diff = min(min_diff, min_sums[i] - max_sums[i])

        return min_diff