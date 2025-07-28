    @cache
    def recur(cur_or, i):
        if i == n and cur_or != target:
            return 0
        if cur_or == target:
            return 2 ** (n-i)
        
        cnt = 0
        cnt += recur(cur_or|nums[i], i+1)
        cnt += recur(cur_or, i +1)
        return cnt