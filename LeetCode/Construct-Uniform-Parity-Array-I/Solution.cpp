class Solution:
    def checkUniformParity(self, nums1: List[int]) -> bool:
        n = len(nums1)
        evens = 0
        odds = 0
        first_odd_idx = -1

        # 1. Analyze the array to count parities and find our "Key"
        for i in range(n):
            if nums1[i] % 2 == 0:
                evens += 1
            else:
                odds += 1
                if first_odd_idx == -1:
                    first_odd_idx = i  # Save the first odd number we find

        # 2. If the array is already uniform, we don't need to do anything.
        # We can just choose nums2[i] = nums1[i] for all elements.
        if evens == 0 or odds == 0:
            return True

        # 3. If it's mixed, we MUST convert everything to Odd.
        # (We cannot convert everything to Even, because Odd - Even = Odd).
        # We use the first odd number we found as our "Key".
        key_val = nums1[first_odd_idx]

        # 4. Construct nums2 (Optional: The problem only asks to return True/False, 
        # but this proves we can actually build the array).
        nums2 = [0] * n
        
        for i in range(n):
            if nums1[i] % 2 == 1:
                # It's already Odd, keep it.
                nums2[i] = nums1[i]
            else:
                # It's Even. Subtract the Odd Key to make it Odd!
                # Even - Odd = Odd
                nums2[i] = nums1[i] - key_val

        # Since we mathematically proved we can always convert a mixed array to all Odds 
        # as long as there is at least one Odd number present, the answer is always True.
        return True