class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        first = prev = None
        a = b = c = 0
        min_dist = inf
        i = 1
        res = [-1, -1]
        while head:
            a, b, c = b, c, head.val
            if a and b and c and (a > b < c or a < b > c):
                if first is None:
                    first = i
                else:
                    min_dist = min(min_dist, i - prev)
                    res = [min_dist, i - first]
                prev = i
            i += 1
            head = head.next
        return res